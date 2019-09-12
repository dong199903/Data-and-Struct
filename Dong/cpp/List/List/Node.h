/*************************************************************************
 > File Name: Node.h
 > Author:    DongZePing
 > Mail:      1939485575@qq.com
 > Time:      2019-07-27
 >
 > 1）支持简单的增删改查
 > 2）支持模板泛型编程
 > 3）支持添加第三方类成员(Tip:有指针的需要实现深拷贝构造)
 ************************************************************************/
#pragma once
#ifndef NODE_H
#define NODE_H
template<class T>
class Node
{
public:
	Node()
	{

	}
	T data;
	Node* next;
};
#endif // !NODE_H

