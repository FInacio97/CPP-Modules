# include <string>
# include <iostream>
# include <fstream>

static void content_management(std::string file_content, char **av)
{
	std::size_t	position;
	std::string original = av[2];
	std::string copy = av[3];

	if (original != copy)
	{
		while (1)
		{
			position = file_content.find(original);
			if (position == std::string::npos)
				break ;
			file_content.erase(position, original.length());
			file_content.insert(position, copy);
		}
	}
	std::string outfile = av[1];
	outfile += ".replace";
	std::ofstream ofs(outfile.c_str());
	ofs << file_content;
	ofs.close();
}

static bool file_extraction(char *path, std::string *file_content)
{
	std::ifstream	ifs (path);
	std::string		buffer;
	int				flag = 0;

	if (ifs.fail())
	{
		std::cout << "file failed to open" << std::endl;
		return (false);
	}
	std::getline(ifs, *file_content);
	if (ifs.eof())
		return (false);
	while (flag == 0)
	{
		std::getline(ifs, buffer);
		if (ifs.eof())
			flag = 1;
		*file_content += "\n" + buffer;
	}
	ifs.close();
	return (true);
}

int main(int ac, char **av)
{
	std::string file_content;

	if (ac != 4)
	{
		std::cout << "Wrong number of arguments" << std::endl;
		return (1);
	}
	if (!av[2] || !av[2][0])
	{
		std::cout << "Cannot contain empty arguments" << std::endl;
		return (1);
	}
	if (file_extraction(av[1], &file_content) == true)
		content_management(file_content, av);
}







// int mmmain()
// {
// 	std::ifstream	ifs("test.txt");
// 	std::string 	buffer;
// 	std::string		file_content;
// 	int				flag = 0;
// 	std::size_t		position;

// 	std::getline(ifs, file_content);
// 	if (ifs.eof())
// 		return (0);
// 	while (flag == 0)
// 	{
// 		std::getline(ifs, buffer);
// 		if (ifs.eof())
// 			flag = 1;
// 		file_content += "\n" + buffer;
// 	}
// 	position = file_content.find("macaco");
// 	file_content.erase(position, 6);
// 	file_content.insert(position, "crocodilo");

// 	std::cout << file_content;

// 	ifs.close();

// }