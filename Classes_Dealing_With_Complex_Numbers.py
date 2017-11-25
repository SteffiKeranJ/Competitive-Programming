"""
Question link: https://www.hackerrank.com/challenges/class-1-dealing-with-complex-numbers/problem
 
"""

import math
class Complex(object):
    def __init__(self, real, imaginary):
        self.real = real
        self.imaginary = imaginary
    
	def __add__(self, no):
	"""
	Addition of two complex numbers
	"""
        c_real = self.real
        c_complex = self.imaginary
        d_real = no.real
        d_complex = no.imaginary
        add_result_real = c_real + d_real
        add_result_imaginary = c_complex + d_complex
        add_result = Complex(add_result_real, add_result_imaginary)
        return add_result
    
	def __sub__(self, no):
	"""
	Subtraction of two complex numbers
	"""
		c_real = self.real
        c_complex = self.imaginary
        d_real = no.real
        d_complex = no.imaginary
        sub_result_real = c_real - d_real
        sub_result_imaginary = c_complex - d_complex
        sub_result = Complex(sub_result_real, sub_result_imaginary)
        return sub_result

    def __mul__(self, no):
	"""
	Multiplication of two complex numbers
	"""
		r1 = self.real
        i1 = self.imaginary
        r2 = no.real
        i2 = no.imaginary
        result_real = (r1*r2-i1*i2)
        result_imaginary = (r1*i2+r2*i1)
        result = Complex(result_real, result_imaginary)
        return result

    def __truediv__(self, no):
	"""
	Division of two complex numbers
	"""
        r1 = self.real
        i1 = self.imaginary
        r2 = no.real
        i2 = no.imaginary
        result_real = float(float(r1*r2+i1*i2)/float(r2*r2+i2*i2))
        result_imaginary = float(float(r2*i1-r1*i2)/float(r2*r2+i2*i2))
        result = Complex(result_real, result_imaginary)
        return result
    
	def mod(self):
	"""
	Modulo of a complex number
	"""
        result = ((self.real)**2 +(self.imaginary)**2)**(1/2.0)
        result = Complex(result, 0)
        return result
    
	def __str__(self):
        if self.imaginary == 0:
            result = "%.2f+0.00i" % (self.real)
        elif self.real == 0:
            if self.imaginary >= 0:
                result = "0.00+%.2fi" % (self.imaginary)
            else:
                result = "0.00-%.2fi" % (abs(self.imaginary))
        elif self.imaginary > 0:
            result = "%.2f+%.2fi" % (self.real, self.imaginary)
        else:
            result = "%.2f-%.2fi" % (self.real, abs(self.imaginary))
        return result

if __name__ == '__main__':
    c = map(float, input().split()) # Get input from the console
    d = map(float, input().split()) # Get input from the console
    x = Complex(*c) # Complex number 1
    y = Complex(*d) # Complex number 2
    print(*map(str, [x+y, x-y, x*y, x/y, x.mod(), y.mod()]), sep='\n')