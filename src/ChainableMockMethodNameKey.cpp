/***
   emock is a cross-platform easy-to-use C++ Mock Framework based on mockcpp.
   Copyright [2017] [ez8.co] [orca <orca.zhang@yahoo.com>]

   This library is released under the Apache License, Version 2.0.
   Please see LICENSE file or visit https://github.com/ez8-co/emock for details.

   mockcpp is a C/C++ mock framework.
   Copyright [2008] [Darwin Yuan <darwin.yuan@gmail.com>]

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

      http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
***/

#include <emock/ChainableMockMethodNameKey.h>

EMOCK_NS_START

/////////////////////////////////////////////////////
ChainableMockMethodNameKey::
ChainableMockMethodNameKey(const std::string& name)
   : methodName(name)
{
}

/////////////////////////////////////////////////////
bool
ChainableMockMethodNameKey::
equals(const ChainableMockMethodKey * const rhs) const
{
   if(rhs == 0)
   {
      return false;
   }

   if(rhs == this)
   {
      return true;
   }

   ChainableMockMethodNameKey* key = \
          dynamic_cast<ChainableMockMethodNameKey*>(
              const_cast<ChainableMockMethodKey*>(rhs));
   if(key == 0)
   {
      return false;
   }
   
   return key->getMethodName() == this->getMethodName();
}

/////////////////////////////////////////////////////
std::string&
ChainableMockMethodNameKey::
getMethodName() const
{
   return const_cast<std::string&>(this->methodName);
}

/////////////////////////////////////////////////////

EMOCK_NS_END

