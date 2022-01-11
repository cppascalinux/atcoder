import torch
print(torch.__version__)
s=torch.zeros(1,1,3,3)
for i in range(1000):
	torch.backends.cudnn.benchmark = False
	torch.backends.cudnn.deterministic = True
	torch.use_deterministic_algorithms(True)
	# torch.manual_seed(0)
	a=torch.tensor([0,1,1,0,0,1,1,0,0,2,2,0,1,1,1,1]).view(1,1,4,4).float()
	c=torch.tensor([0,0,0,1,0,-1,1,0,-1]).view(1,1,3,3).float()
	ans=torch.tensor([-2,-2,2,2,-4,-4,4,4,-4,-3,3,4,-3,-2,2,3]).view(1,1,4,4).float()
	cv=torch.nn.Conv2d(1,1,3,padding=1)
	cv.weight.data=c
	# print(cv.weight)
	out=cv(a)
	# print(out)
	loss=torch.nn.MSELoss()(ans,cv(a))
	loss.backward()
	s+=cv.weight.grad
	# print(cv.weight.grad)
print(s/1000)