#encoding:utf-8

op_config = {'+':1,'-':1,'*':2,'/':2,'(':3,')':3}
operators = []

def process(str):
	str = pre_process(str)
	if str == None:
		return None
	tokens = get_token(str)
	if tokens != None:
		print "%s＝%s\n"%(str,calc(tokens)[0])

def pre_process(str):
	if not (str[0].isdigit() or str[0] == '('):
		print "非法字符'%s'" % str[0]
		return None
	return str

def get_token(str):
	result = []
	length = len(str)
	index  = 0
	while index<length:
		if str[index] == '' or str[index] == '\t':
			pass
		elif str[index].isdigit():
			i = index;
			while index<length and str[index].isdigit() :
				index += 1
			result.append(str[i:index])
			index -= 1
		elif op_config.has_key(str[index]):
			r = process_operators(str[index])
			if r != None:
				for j in r:
					result.append(j)
		else:
			print "非法字符'%s'"%str[index]
			return None
		index += 1
	global operators
	while operators != []:
		result.append(operators.pop())
	operators = []
	return result

def process_operators(op):
	res = []
	if  operators==[] or op == '(':
		operators.append(op)
		return None
	elif op == ')':
		o = operators.pop()
		while o != '(':
			res.append(o)
			o = operators.pop()
		return res
	elif op_config[operators[-1]]>op_config[op] and operators[-1] != '(':
		o = operators.pop()
		while o != '(':
			res.append(o)
			if operators != []:
				o = operators.pop()
			else:
				break
		if o == '(':
			operators.append(o)
		operators.append(op)
		return res
	else:
		operators.append(op)

def calc(e_list):
	data = []
	for e in e_list:
		if e.isdigit():
			data.append(e)
		else:
			result = calculate(data.pop(),data.pop(),e)
			if type(result) != int:
				data = ['除数为0，重新输入\n']
				return data
			data.append(result)
	return data

def calculate(oprands1,oprands2,op):
	oprands1 = int(oprands1)
	oprands2 = int(oprands2)
	if op == '+':
		return oprands1+oprands2
	elif op == '-':
		return oprands2-oprands1
	elif op == '*':
		return oprands1*oprands2
	elif op == '/':
		try:
			res = oprands2/oprands1
		except ZeroDivisionError:
			res = '除数为0，重新输入\n'
		return res

while True:
	str = raw_input("请输入:")
	if str == "q":
		break
	else:
		process(str.strip())