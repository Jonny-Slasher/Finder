#include "Finder.h"

FileEngine::FileEngine(std::wstring wpath)
{
	path = wpath;
}

void FileEngine::SetPath(std::wstring twpath)
{
	path = twpath;
}

void FileEngine::SetSearchName(std::string ts_name)
{
	searchname = ts_name;
}

std::vector<std::string> FileEngine::GetFileList() const
{
	return fileslist;
}

int FileEngine::GetId() const
{
	return ID;
}

bool FileEngine::IsExist()
{
	fs::file_status s = fs::file_status{};
	if (fs::status_known(s) ? fs::exists(s) : fs::exists(path))
		return true;

	return false;
}

void FileEngine::RecursiveSearch()
{
	
		std::error_code os_error;
		fs::recursive_directory_iterator walker(path);
		for (auto i = fs::begin(walker); i != fs::end(walker); i = i.increment(os_error)) {
			if (!os_error) {
				std::string temp;
				std::string fileName = walker->path().string();
				temp = fileName;
				temp = TransformToLowerCase(temp);
				if (temp.find(searchname) != temp.npos) {
					fileslist.push_back(fileName);
					ID = ++counter;
				}
			}

			/*try {
				for (auto& entry : fs::recursive_directory_iterator(path)) {
					if (entry.path().wstring().find(L"\u202E") != std::string::npos)
						continue;
					std::string temp;
					std::string fileName = entry.path().string();
					temp = fileName;
					temp = TransformToLowerCase(temp);
					if (temp.find(searchname) != temp.npos) {
						fileslist.push_back(fileName);
						ID = ++counter;
					}
				}
			}
			catch (fs::filesystem_error& e) {
				std::cout << e.what() << std::endl;
			}*/
		}
}

void FileEngine::Print(PrintInterfase* p)
{
	p->Print(fileslist);
}

std::string TransformToLowerCase(std::string to_lower)
{
	std::transform(to_lower.begin(), to_lower.end(), to_lower.begin(), ::tolower);
	return to_lower;
}

int FileEngine::counter = 0;