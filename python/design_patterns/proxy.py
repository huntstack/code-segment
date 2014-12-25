#encoding:utf-8
__metaclass__ = type

class Internet:
	def __init__(self):
		pass

	def google(self):
		print 'google'

	def baidu(self):
		print 'baidu'

class Proxy:
	def __init__(self,object):
		self.__object = object

	def google(self):
		print 'usr proxy'
		self.__object.google()

	def __getattr__(self,name):
		print 'usr proxy'
		return getattr(self.__object,name)
		
if __name__ == '__main__':
	i = Internet()
	p = Proxy(i)
	p.google()
	p.baidu()