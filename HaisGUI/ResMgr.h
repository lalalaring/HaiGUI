#include "pch.h"
enum class ResType
{
	RES_IMAGE,
	RES_SND,
	RES_UNKNOWN

};
class IResource
{
public:
	bool Create(std::wstring path)
	{
		return true;
	}
	void* GetData(){ return data; }
	size_t GetDataSize(){ return size; }
	ResType GetType(){ return type; }
protected:
private:
	ResType type;
	void* data;
	size_t size;
};

class ResMgr
{
public:
	int CreateResource(std::wstring name, std::wstring path);
	bool DestoryResource(int id);
	bool DestoryResource(std::wstring name);
	std::shared_ptr<IResource> GetResource(int id);
	std::shared_ptr<IResource> GetResource(std::wstring name);

protected:
private:
	std::hash_map<std::wstring,IResource*> resmap;
};