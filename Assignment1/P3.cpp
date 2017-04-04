#include <cmath>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

// ---------------- declare global variables ----------------

string url("http://dark.dark-cosmology.dk/~tamarad/SN/");
string data_file_name("Davis07_R07_WV07.dat");
//string data_file_name("error1.dat");
//string data_file_name("error2.dat");
//string data_file_name("error3.dat");
//string data_file_name("error4.dat");

vector<double>               // C++ std template vector type
  z_data,                    // redshift - column 2 in data file
  mu_data,                   // distance modulus - column 3
  mu_err_data,               // error in distance modulus - column 4

  zr_data,                    
  mur_data,                   
  mur_err_data,

  zb_data,                    
  mub_data,                   
  mub_err_data;


// ---------------- function declarations ----------------

void read_data();            // opens and reads the data file

void chi_square_fit(         // makes a linear chi-square fit
  const vector<double>& x,   // vector of x values - input
  const vector<double>& y,   // vector of y values - input
  const vector<double>& err, // vector of y error values - input
  double& a,                 // fitted intercept - output
  double& b,                 // fitted slope - output
  double& sigma_a,           // estimated error in intercept - output
  double& sigma_b,           // estimated error in slope - output
  double& chi_square         // minimized value of chi-square sum - output
);

// ---------------- function definitions ----------------

int main() {

  cout << " Chi-square fit of supernova data to a straight line\n"
       << " Reference: " << url << endl;

  read_data();

  int n = z_data.size();
 
  for (int i = 0; i < n; i++){
    if (z_data[i] < 0.5){
      zr_data.push_back(z_data[i]);
      mur_data.push_back(mu_data[i]);
      mur_err_data.push_back(mu_err_data[i]);
    }
    else{
      zb_data.push_back(z_data[i]);
      mub_data.push_back(mu_data[i]);
      mub_err_data.push_back(mu_err_data[i]);
    }
  }

  int nr = zr_data.size();
  int nb = zb_data.size();
  vector<double> logzr_data(nr);
  vector<double> logzb_data(nb);

  for (int i=0; i < nr; i++)
    logzr_data[i]=log10(zr_data[i]);
  
  for (int i=0; i < nb; i++)
    logzb_data[i]=log10(zb_data[i]);

  double interceptr, sloper, intercept_errr, slope_errr, chisqrr, interceptb, slopeb, intercept_errb, slope_errb, chisqrb;
  chi_square_fit(logzr_data, mur_data, mur_err_data,
                 interceptr, sloper, intercept_errr, slope_errr, chisqrr);
  chi_square_fit(logzb_data, mub_data, mub_err_data,
                 interceptb, slopeb, intercept_errb, slope_errb, chisqrb);

  cout.precision(4);
  cout << " slope of low redshift = " << sloper << " +- " << slope_errr << "\n"
       << " intercept of low redshift= " << interceptr << " +- " << intercept_errr << "\n"
       << " chi-square/d.o.f of low redshift = " << chisqrr / (nr - 2) << endl;

  cout.precision(4);
  cout << " slope of high redshift = " << slopeb << " +- " << slope_errb << "\n"
       << " intercept of high redshift = " << interceptb << " +- " << intercept_errb << "\n"
       << " chi-square/d.o.f of high redshift= " << chisqrb / (nb - 2) << endl;
}

void read_data() {

  // create an input file stream object and open the data file
  ifstream data_file(data_file_name.c_str());
  if (data_file.fail())
    cerr << "sorry, cannot open " << data_file_name << endl;

  // read the data file one line at a time
  string line;                         // string object to hold current line
  while (getline(data_file, line)) {   // std::getline defined in <string>

    if (line[0] == ';')                // skip lines starting with semicolon
      continue;

    string SN;                         // name of supernova in column 1
    double z, mu, mu_err;              // columns 2, 3, 4
    istringstream is(line);            // string stream object to read line
    is >> SN >> z >> mu >> mu_err;     // read successive column entries

    if (is.fail()) {                   // if a read error occurs
      cerr << "error reading line: "
           << line << endl;            // print an error message
      continue;
    }

    // store the data values in the data vectors
    z_data.push_back(z);
    mu_data.push_back(mu);
    mu_err_data.push_back(mu_err);
  }

  cout << " read " << z_data.size() << " data values" << endl;

  data_file.close();
}

void chi_square_fit(         // makes a linear chi-square fit
  const vector<double>& x,   // vector of x values - input
  const vector<double>& y,   // vector of y values - input
  const vector<double>& err, // vector of y error values - input
  double& a,                 // fitted intercept - output
  double& b,                 // fitted slope - output
  double& sigma_a,           // estimated error in intercept - output
  double& sigma_b,           // estimated error in slope - output
  double& chi_square)        // minimized value of chi-square sum - output
{
  int n = x.size();

  assert(n >= 2);

  double S = 0, S_x = 0, S_y = 0;
  for (int i = 0; i < n; i++) {
    assert ( fabs(err[i]) >= 0.000001 );
    S += 1 / err[i] / err[i];
    S_x += x[i] / err[i] / err[i];
    S_y += y[i] / err[i] / err[i];
  }

  vector<double> t(n);
  for (int i = 0; i < n; i++)
    t[i] = (x[i] - S_x/S) / err[i];

  double S_tt = 0;
  for (int i = 0; i < n; i++)
    S_tt += t[i] * t[i];

  b = 0;
  for (int i = 0; i < n; i++)
    b += t[i] * y[i] / err[i];
  assert( fabs(S_tt) > 0.00001);
  b /= S_tt;

  assert( fabs(S) > 0.00001);
  a = (S_y - S_x * b) / S;
  sigma_a = sqrt((1 + S_x * S_x / S / S_tt) / S);
  sigma_b = sqrt(1 / S_tt);

  chi_square = 0;
  for (int i = 0; i < n; i++) {
    double diff = (y[i] - a - b * x[i]) / err[i];
    chi_square += diff * diff;
  }
}
