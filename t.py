# Author : ysh
# 2026/11/06 Fri 14:54:56
import numpy as np

# Doolittle矩阵分解函数
def DoolittleDecompose(A):
	global L, U
	size   = A.shape[0]												   # 方阵的大小
	L	  = np.identity(size)											# 初始化L为单位矩阵
	U	  = np.zeros((size,size))										# 初始化U全为0
	U[0,:] = A[0,:].copy()												# 计算U的第一行
	L[:,0] = A[:,0]/U[0,0]												# 计算L的第一列
	pp()
																		 
	for i in range(1,size):											   # 逐行、列计算U和L
		U[i,:] =  A[i,:] - L[i,:i]@U[:i,:]								 # 计算U的第i行
		L[:,i] = (A[:,i] - L[:,:i]@U[:i,i])/U[i,i]						 # 计算L的第i列
		pp()
	   
	# 为避免过程中产生的一些微小数值问题,将L上三角元素、U的下三角元素置0
	L=np.tril(L)														  # L只取下三角
	U=np.triu(U)														  # U只取上三角
	return L,U

def pp():
	print('\n-----需要分解的矩阵A-----')								  # 打印标题
	print('A=\n',A)													   # 打印矩阵A

	print('\n--------分解的结果------')								   # 打印标题
	print('L=\n',L)													   # 打印分解后得到的L
	print('\nU=\n',U)													 # 打印分解后得到的U

	print('\n---------结果验证--------')								  # 打印标题
	print('\nL*U=\n',L@U)			 

	input()

# 测试样例
if __name__ == "__main__":
	A   = np.array([[1.,2.,5,8],[3.,5.,4,2],[6.,4,3,1],[2.,3,5,5]]).T	 # 生成需要分解的矩阵A
	L,U = DoolittleDecompose(A)										   # 将A进行Doolittle分解
	pp()