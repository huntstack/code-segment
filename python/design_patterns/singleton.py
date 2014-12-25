#encoding:utf-8
__metaclass__ = type

def singleton(cls):
	instance = {}
	def _singleton(*args,**kwargs):
		if cls not in instance:
			instance[cls] = cls(*args,**kwargs)
		return instance[cls]
	return _singleton

@singleton
class ASmallClass:
	def __init__(self):
		self.var = 'unique'

if __name__ == '__main__':
	a = ASmallClass()
	b = ASmallClass()
	print type(ASmallClass)
	print hex(id(a))
	print hex(id(b))


# class ASmallClass:

# 	def __init__(self):
# 		self.__var = 'unique'

# 	def __new__(cls,*arg,**args):
# 		if not hasattr(cls,'_instance'):
# 			cls._instance = super(ASmallClass,cls).__new__(cls,*arg,**args)
# 		return cls._instance


# if __name__ == '__main__':
# 	a = ASmallClass()
# 	b = ASmallClass()
# 	print hex(id(a))
# 	print hex(id(b))


# class ASmallClass:

# 	def __init__(self):
# 		self.var = 'unique'
# 	@staticmethod
# 	def get_instance():
# 		if not hasattr(ASmallClass,'_instance'):
# 			ASmallClass._instance = ASmallClass()
# 		return ASmallClass._instance

# if __name__ == '__main__':
# 	a = ASmallClass.get_instance()
# 	b = ASmallClass.get_instance()
# 	print hex(id(a))
# 	print hex(id(b))