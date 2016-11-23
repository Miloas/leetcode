class Solution(object):
	def simplifyPath(self,path):
		paths = path.split("/");
		i = 0;
		while(i<len(paths)):
			p=paths[i];
			if(p==''):
				del paths[i];
				i-=1;
			elif(p=='..'):
				del paths[i];
				if(i>0):
					del paths[i-1];
					i-=2;
				else:
					i-=1;
			elif(p=='.'):
				del paths[i];
				i-=1;
			i+=1;
		return '/'+'/'.join(paths);
