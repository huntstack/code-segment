#encoding:utf-8

class Decoration:
	@staticmethod
	def complete_eat(func):
		def warpper(instance,s):
			print 'xishou'
			func(instance,s)
		return warpper

	@staticmethod
	def finally_eat(func):
		def warpper(instance,s):
			func(instance,s)
			print 'cazui'
			print 'wc'
		return warpper

class Anjuke:
	def __init__(self):
		pass
	@Decoration.complete_eat
	@Decoration.finally_eat
	def eat(self,something):
		print 'chi',something

if __name__ == '__main__':
	a = Anjuke()
	a.eat('apple')