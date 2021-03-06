//------------------------------------------------------------------------------
// RegisterValues.cpp
//    
//   This file holds RegisterValues, a class meant to stores the values 
//   of the four main registers [usually after a CPUID instruction]. 
//   
// 
//   Copyright (c) 2001 Paul Wendt [p-wendt@wideopenwest.com]
// 
#include "RegisterValues.h"

RegisterValues::RegisterValues()
{
   setEaxValue(0);
   setEbxValue(0);
   setEcxValue(0);
   setEdxValue(0);
}

RegisterValues::RegisterValues(DWORD dwEax, DWORD dwEbx, DWORD dwEcx, DWORD dwEdx)
{
   setEaxValue(dwEax);
   setEbxValue(dwEbx);
   setEcxValue(dwEcx);
   setEdxValue(dwEdx);
}

RegisterValues::RegisterValues(const RegisterValues& source)
{
   assign(source);
}

RegisterValues& RegisterValues::operator=(const RegisterValues& right)
{
   if (this != &right)
   {
      assign(right);
   }

   return (*this);
}

RegisterValues::~RegisterValues()
{
   // nothing to do yet
}

void RegisterValues::assign(const RegisterValues& source)
{
   setEaxValue(source.getEaxValue());
   setEbxValue(source.getEbxValue());
   setEcxValue(source.getEcxValue());
   setEdxValue(source.getEdxValue());
}
