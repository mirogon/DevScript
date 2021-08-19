#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <cstdlib>
#include <filesystem>

template <class T, class U>
inline bool IsType(T* t)
{
   if(dynamic_cast<U*>(t) != nullptr) 
   {
       return true;
   }
   return false;
}