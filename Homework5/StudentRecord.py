class StudentRecord:
   lastname_ = ""
   firstname_ = ""
   score_ = 0.

   def __init__ ( self, firstname="", lastname="", score=0.) :
       self.firstname_ = firstname
       self.lastname_ = lastname
       self.score_ = float(score)

   def __add__ ( self, right ):
       return self.score_ + right.score_

   def input( self, line ):
       self.lastname_,self.firstname_,s = [s.strip() for s in line.split(",")]
       self.score_ = float(s)

   def __str__(self ):
       print self.firstname_ + ' ' +self.lastname_ + ',' + str(self.score_)

   def score(self ):
       return self.score_
    


