/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:58:17 by mababou           #+#    #+#             */
/*   Updated: 2022/03/25 17:06:49 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

std::string replacer(std::string line, std::string s1, std::string s2)
{
	if (s1.length() > line.length())
		return (line);

	size_t i = 0;
	std::string output;

	while (42)
	{
		i = line.find(s1);
		if (i == std::string::npos) {
			output += line;
			break ;
		}
		else {
			output += line.substr(0, i);
			output += s2;
			i += s1.length();
			line = line.substr(i, line.length());
		}
	}	
	return (output);
}


int main(int ac, char **av)
{
	bool nl = false;

	if (ac != 4)
	{
		std::cerr << "Invalid number of arguments <filename, s1, s2>" << std::endl;
		return (1);
	}
	
	std::ifstream	src_file;
	std::ofstream	dest_file;
	std::string 	dest_filename(av[1]);
	bool			start = true;

	dest_filename.append(".replace");
	
	src_file.open(av[1], std::ifstream::in);
	
	if (!src_file) {
		std::cerr << "\e[31mAn error occured while opening the input file\e[0m" << std::endl;
		return (1);
	}

	dest_file.open(dest_filename.data(), std::ofstream::out | std::ofstream::trunc);
	if (!dest_file) {
		std::cerr << "\e[31mAn error occured while creating the output file\e[0m" << std::endl;
		return (1);
	}

	src_file.seekg(-1, src_file.end);	
	char c;
	src_file.get(c);
	if (c == '\n') {
		nl = true;
	}
	src_file.seekg(0, src_file.beg);	

	std::string line;
	
	while (std::getline(src_file, line)) {
		if (start)
			start = false;
		else
			dest_file << std::endl;
		dest_file << replacer(line, av[2], av[3]);	
	}
	
	if (nl)
		dest_file << std::endl;

	src_file.close();
	dest_file.close();

	return (0);
}