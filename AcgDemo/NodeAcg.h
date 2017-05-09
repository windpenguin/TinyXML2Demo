#pragma once
  
#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
  
class MsItemData
{
public:
	MsItemData(){}

public:
	uint32 idItemType;
	uint32 amount;
};


class MsClanInfo
{
public:
	MsClanInfo(){}

public:
	uint32 clanId;
	string clanName;
};


class MsUserInfoLite
{
public:
	MsUserInfoLite(){}

public:
	uint32 roleId;
	string roleName;
};


class MsUserInfo : public MsUserInfoLite
{
public:
	MsUserInfo(){}

public:
	uint32 vipLev;
	uint32 lastLogin;
	MsClanInfo clanInfo;
	vector<uint32> numVec;
	map<uint32,uint32> numMap;
	vector<MsItemData> itemVec;
	map<uint32,MsItemData> itemMap;
	map<uint32,map<uint32,MsItemData>> itemMapMap;
};


string DebugClass(const class MsItemData& mb)
{
	ostringstream oss;
	oss << "{ ";
	oss << "idItemType:" << mb.idItemType << " ";
	oss << "amount:" << mb.amount << " ";
	oss << "} ";
	return oss.str();
}
string DebugClass(const class MsClanInfo& mb)
{
	ostringstream oss;
	oss << "{ ";
	oss << "clanId:" << mb.clanId << " ";
	oss << "clanName:" << mb.clanName << " ";
	oss << "} ";
	return oss.str();
}
string DebugClass(const class MsUserInfoLite& mb)
{
	ostringstream oss;
	oss << "{ ";
	oss << "roleId:" << mb.roleId << " ";
	oss << "roleName:" << mb.roleName << " ";
	oss << "} ";
	return oss.str();
}
string DebugClass(const class MsUserInfo& mb)
{
	ostringstream oss;
	oss << "{ ";
	oss << "MsUserInfoLite: " << DebugClass(static_cast<const MsUserInfoLite&>(mb));
	oss << "vipLev:" << mb.vipLev << " ";
	oss << "lastLogin:" << mb.lastLogin << " ";
	oss << "clanInfo:" << DebugClass(mb.clanInfo);
	oss << "numVec:" << "[ ";
	for_each(mb.numVec.begin(), mb.numVec.end(), [&oss](const uint32& data)->void
	{
		oss << data << " ";
	});
	oss << "] ";
	oss << "numMap:" << "{ ";
	for_each(mb.numMap.begin(), mb.numMap.end(), [&oss](const pair<uint32,uint32>& data)->void
	{
		oss << "[ ";
		oss << data.first << " ";
		oss << data.second << " ";
		oss << "]";
	});
	oss << " } ";
	oss << "itemVec:" << "[ ";
	for_each(mb.itemVec.begin(), mb.itemVec.end(), [&oss](const MsItemData& data)->void
	{
		oss << DebugClass(data);
	});
	oss << "] ";
	oss << "itemMap:" << "{ ";
	for_each(mb.itemMap.begin(), mb.itemMap.end(), [&oss](const pair<uint32,MsItemData>& data)->void
	{
		oss << "[ ";
		oss << data.first << " ";
		oss << DebugClass(data.second);
		oss << "]";
	});
	oss << " } ";
	oss << "itemMapMap:" << "{ ";
	for_each(mb.itemMapMap.begin(), mb.itemMapMap.end(), [&oss](const pair<uint32,map<uint32,MsItemData>>& data)->void
	{
		oss << "[ ";
		oss << data.first << " ";
		oss << "{ ";
		for_each(data.second.begin(), data.second.end(), [&oss](const pair<uint32,MsItemData>& data)->void
		{
			oss << "[ ";
			oss << data.first << " ";
			oss << DebugClass(data.second);
			oss << "]";
		});
		oss << " } ";
		oss << "]";
	});
	oss << " } ";
	oss << "} ";
	return oss.str();
}
