// get.h

#ifndef get_header
#define get_header

#include <iostream>
#include <string>

bool		get_bool(const std::string & prompt = "");

char		get_char(const std::string & prompt = "");

short		get_short(const std::string & prompt = "");

int			get_int(const std::string & prompt = "");

long		get_long(const std::string & prompt = "");

float		get_float(const std::string & prompt = "");

double		get_double(const std::string & prompt = "");

std::string	get_string(const std::string & prompt = "");

bool		get_bool(std::istream & is, const std::string & prompt = "");

char		get_char(std::istream & is, const std::string & prompt = "");

short		get_short(std::istream & is, const std::string & prompt = "");

int			get_int(std::istream & is, const std::string & prompt = "");

long		get_long(std::istream & is, const std::string & prompt = "");

float		get_float(std::istream & is, const std::string & prompt = "");

double		get_double(std::istream & is, const std::string & prompt = "");

std::string	get_string(std::istream & is, const std::string & prompt = "");

#endif
