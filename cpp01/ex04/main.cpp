/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mababou <mababou@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:58:17 by mababou           #+#    #+#             */
/*   Updated: 2022/02/16 20:29:05 by mababou          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && i < n - 1)
	{
		if ((unsigned char)s1[i] != (unsigned char)s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

std::string replacer(std::string line, std::string s1, std::string s2)
{
	if (s1.length() > line.length())
		return (line);

	size_t i = 0;
	const char *str = line.data();
	std::string output;

	while (i < line.length())
	{
		if (i + s1.length() <= line.length() && !line.substr(i, s1.length()).compare(s1))
		// if (!ft_strncmp(str + i, s1.data(), s1.length()))
		{
			output.append(s2);
			i += s1.length();
		}
		else
		{
			output.push_back(str[i]);
			i++;
		}
	}
	
	return (output);
}


int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Invalid number of arguments <filename, s1, s2>" << std::endl;
		return (1);
	}
	
	std::ifstream	src_file;
	std::ofstream	dest_file;
	std::string 	dest_filename;

	dest_filename = (std::string)av[1];
	dest_filename.append(".replace");
	
	src_file.open(av[1], std::ios::in);
	dest_file.open(dest_filename.data());

	std::string line;

	while (std::getline(src_file, line))
	{
		dest_file << replacer(line, av[2], av[3]) << std::endl;
	}
	
	src_file.close();
	dest_file.close();
}