#encoding:utf-8
__metaclass__ = type

class Obserbver:
	def update(self,arg):
		pass
	def display(self):
		passx

class Subject:
	def add_observer(self,obserbver):
		pass
	def remote_observer(self,obserbver):
		pass
	def notify_observer(self):
		pass

class Welfare(Subject):
	def __init__(self):
		self.observers = []
		self.money = 0
	def add_observer(self,obserbver):
		self.observers.append(obserbver)
	def remote_observer(self,obserbver):
		self.observers.remove(obserbver)
	def notify_observer(self):
		for ob in self.observers:
			ob.update(self.money)
	def __setattr__(self,name,value):
		self.__dict__[name] = value
		self.notify_observer()

class Zhangle(Obserbver):
	def __init__(self,subject):
		self.subject = subject
		self.money = 0
		self.subject.add_observer(self)
	def update(self,money):
		self.money = money
		self.display()
	def display(self):
		print '%s,福利==>%s'%(self.__class__.__name__,self.money)

class weisongju(Obserbver):
	def __init__(self,subject):
		self.subject = subject
		self.money = 0
		self.subject.add_observer(self)
	def update(self,money):
		self.money = money
		self.display()
	def display(self):
		print '%s,福利==>%s'%(self.__class__.__name__,self.money)

if __name__ == '__main__':
	w = Welfare()
	z = Zhangle(w)
	wei = weisongju(w)
	w.money = 500
