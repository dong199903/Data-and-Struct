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
		//��ʼBF�㷨
		for (i = 0; i < s1.length(); i++)
		{
			begin = i;//�������λ��
			j = 0;//ģʽ�����λ��
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
		//��¼ģʽ��ÿ���ַ������ֵ�λ��(�����ģʽ��)
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
		1.ÿ�������������ģʽ������ַ�ƥ��
		2.��������ƥ��ʱ������ȥ������Ӧ��һ����㴦��һ���ַ�λ����index
		3.��ʱ�����ַ���ģʽ�������ͷ��β��Ӧ����
		4.���û�ҵ����ͽ��������α�ֱ���ƶ���index+1,ģʽ���ع鵽0
		5.����ҵ���,��ȷ��ģʽ���ҵ���λ��x,Ȼ��鿴��Ԫ����ģʽ��������λ��y�����������α�ֱ�Ӽ���ģʽ������-���λ��
		*/


		
		for (i = 0; i < s1.length(); )
		{
			temp = i;//temp�����α�
			j = 0;//jģʽ���α�
			while (s1.charAt(temp)==s2.charAt(j))
			{
				temp++;
				j++;
				if (j == s2.length())
				{
					return i;
				}
			}
			//��ʱ�����±�temp,ģʽ���±�j��ƥ����,����������һ�����ch
			ch = s1.charAt(i + s2.length());
			//��ģʽ������ͷ�ң��Ƿ������ch��ȵ�ֵ
			j = 0;
			while (s2.charAt(j)!=ch)
			{
				j++;
				if (j == s2.length())
				{
					break;
				}
			}
			//�ж��Ƿ��ҵ������ֵch
			if (j == s2.length())//û���ҵ�
			{
				i += s2.length() + 1;
			}
			else//�ҵ���
			{
				i += s2.length() - index[j];
			}
		}
		return -1;
	}
	
	
	public int RK()
	{
		//׼��һ��������һ��������(��������������ַ�����Χ����)
		int q = 144451,d = 26;//�����ҵ��ַ���ȫ��a-z���,��Χ��26��������26���ơ�
		int main_Str = s1.charAt(0) - 'a';//������һ���ַ��±�a����0,b����2
		int pat_Str = s2.charAt(0) - 'a';//ģʽ����һ���ַ��±�
		int h = 1,begin,j,i;//26�Ķ����ݴη�
		for (i = 1; i < s2.length(); i++)
		{
			main_Str = (main_Str * 26 + s1.charAt(i) - 'a') % q;
			pat_Str = (pat_Str * 26 + s2.charAt(i) - 'a')% q;
			h = h*d;
		}
		//��ʼ������ıȽ�
		for (i = 0; i < s1.length() - s2.length() + 1; i++)
		{
			//���ж�codeֵ�Ƿ����
			if (main_Str == pat_Str)
			{
				begin = i;//������ʼλ��
				j = 0;
				//��������ַ����ж�
				while (s1.charAt(begin)==s2.charAt(j))
				{
					begin++;
					j++;
					if (j == s2.length())
					{
						return i;//ƥ��ok
					}
				}
			}
			//code���Ȼ���ƥ��ʧ�ܣ��͸���main_Str��ֵ����һ��
			//code���°취�Ǽ�ȥ���λ�Ľ��ƣ�ʣ�������*26 +���½���������
			main_Str = (   (main_Str - h*(s1.charAt(i)-'a')) * d    +    s1.charAt(i + s2.length()) - 'a'   )%q;
		}
		return -1;
	}
}
