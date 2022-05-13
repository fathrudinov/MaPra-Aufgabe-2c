// Copyright (c) 2022, The MaPra Authors.
#include "mapra_test.h"
#include "student.h"
#include <cstring>
#include <fstream>

// Eingabeoperator ">>"
std::istream &mapra::operator>>(std::istream &s, mapra::Student &a)
{
  s >> a.first_name >> a.last_name >> a.matr_nr >> a.grade;
  return s;
}

// Ausgabeoperator "<<"
std::ostream &mapra::operator<<(std::ostream &s, const mapra::Student &a)
{
  s << a.first_name << " " << a.last_name << " " << a.matr_nr << " " << a.grade;
  return s;
}

// Vergleichsoperator "<"
bool mapra::operator<(const mapra::Student &a, const mapra::Student &b)
{
  int result = strcmp(a.last_name.c_str(), b.last_name.c_str());
  if (result < 0)
    return true;
  else if (result == 0)
  {
    if (strcmp(a.first_name.c_str(), b.first_name.c_str()) < 0)
    {
      return true;
    }
  }
  return false;
}

// Vergleichsoperatoren "==" bzw. "!="
bool mapra::operator==(const mapra::Student &a, const mapra::Student &b)
{
  if (a.last_name.c_str() == b.last_name.c_str() && a.first_name.c_str() == b.first_name.c_str())
  {
    return true;
  }
  return false;
}

bool mapra::operator!=(const mapra::Student &a, const mapra::Student &b)
{
  return !(a == b);
}
