#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>
#include <cstdlib>
#include <filesystem>
#include <fstream>

template <class T, class U>
inline bool IsType(T* t)
{
   if(dynamic_cast<U*>(t) != nullptr) 
   {
       return true;
   }
   return false;
}

template <class T, class U>
inline U* DynCast(T* t)
{
    return dynamic_cast<U*>(t);
}