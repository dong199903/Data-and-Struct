package Match_String;

public class Match_String {
	private String s1;
	private String s2;
	public Match_String(String s1,String s2)
	{
		this.s1 = s1;
		this.s2 = s2;
	}
	public int BF()
	{
		int i, j, index,begin,l2;
		if (this.s1.length() < s2.length())
		{
			return -1;
		}
		//开始BF算法
		for (i = 0; i < s1.length(); i++)
		{
			begin = i;//主串起点位置
			j = 0;//模式串起点位置
			while (s1.charAt(begin) == s2.charAt(j))
			{
				begin++;
				j++;
				if (j == s2.length())
				{
					break;
				}
			}
			if (j == s2.length())
			{
				return i;
			}
			else
			{
				begin++;
			}
		}
		return -1;
	}
	
	
	public int Sunday()
	{
		int i, j,  temp;
		int index[] = new int[100];
		char ch;
		//记录模式串每个字符最后出现的位置(相对于模式串)
		for (i = 0; i < s2.length(); i++)
		{
			j = i;
			index[i] = j;
			while (j != s2.length())
			{
				if (s2.charAt(j) == s2.charAt(i))
				{
					index[i] = j;
				}
				j++;
			}
		}
		/*
		1.每次先在主串里和模式串逐个字符匹配
		2.当遇到不匹配时，立马去主串对应下一个起点处找一个字符位置是index
		3.此时将该字符在模式串里面从头到尾对应的找
		4.如果没找到，就将主串的游标直接移动到index+1,模式串回归到0
		5.如果找到了,先确定模式串找到的位置x,然后查看此元素在模式串最后出现位置y，让主串的游标直接加上模式串长度-最后位置
		*/


		
		for (i = 0; i < s1.length(); )
		{
			temp = i;//temp主串游标
			j = 0;//j模式串游标
			while (s1.charAt(temp)==s2.charAt(j))
			{
				temp++;
				j++;
				if (j == s2.length())
				{
					return i;
				}
			}
			//此时主串下标temp,模式串下标j不匹配了,来到主串下一个起点ch
			ch = s1.charAt(i + s2.length());
			//在模式串，从头找，是否存在与ch相等的值
			j = 0;
			while (s2.charAt(j)!=ch)
			{
				j++;
				if (j == s2.length())
				{
					break;
				}
			}
			//判断是否找到了这个值ch
			if (j == s2.length())//没有找到
			{
				i += s2.length() + 1;
			}
			else//找到了
			{
				i += s2.length() - index[j];
			}
		}
		return -1;
	}
	
	
	public int RK()
	{
		//准备一个素数和一个进制数(进制数按照你的字符串范围进行)
		int q = 144451,d = 26;//假设我的字符串全是a-z组成,范围是26，进制用26进制。
		int main_Str = s1.charAt(0) - 'a';//主串第一个字符下标a就是0,b就是2
		int pat_Str = s2.charAt(0) - 'a';//模式串第一个字符下标
		int h = 1,begin,j,i;//26的多少幂次方
		for (i = 1; i < s2.length(); i++)
		{
			main_Str = (main_Str * 26 + s1.charAt(i) - 'a') % q;
			pat_Str = (pat_Str * 26 + s2.charAt(i) - 'a')% q;
			h = h*d;
		}
		//开始逐个串的比较
		for (i = 0; i < s1.length() - s2.length() + 1; i++)
		{
			//先判断code值是否相等
			if (main_Str == pat_Str)
			{
				begin = i;//主串开始位置
				j = 0;
				//继续逐个字符的判断
				while (s1.charAt(begin)==s2.charAt(j))
				{
					begin++;
					j++;
					if (j == s2.length())
					{
						return i;//匹配ok
					}
				}
			}
			//code不等或者匹配失败，就更新main_Str的值是下一个
			//code更新办法是减去最高位的进制，剩余的数字*26 +最新进来的数字
			main_Str = (   (main_Str - h*(s1.charAt(i)-'a')) * d    +    s1.charAt(i + s2.length()) - 'a'   )%q;
		}
		return -1;
	}
}
