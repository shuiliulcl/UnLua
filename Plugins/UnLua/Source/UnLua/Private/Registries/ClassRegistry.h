﻿// Tencent is pleased to support the open source community by making UnLua available.
// 
// Copyright (C) 2019 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the MIT License (the "License"); 
// you may not use this file except in compliance with the License. You may obtain a copy of the License at
//
// http://opensource.org/licenses/MIT
//
// Unless required by applicable law or agreed to in writing, 
// software distributed under the License is distributed on an "AS IS" BASIS, 
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. 
// See the License for the specific language governing permissions and limitations under the License.

#pragma once

#include "lua.h"
#include "ReflectionUtils/ClassDesc.h"

namespace UnLua
{
    class FClassRegistry
    {
    public:
        explicit FClassRegistry(lua_State* GL);

        static FClassRegistry* Find(const lua_State* L);

        static FClassDesc* Find(const char* TypeName);

        static FClassDesc* Find(const UStruct* Type);

        static FClassDesc* RegisterReflectedType(const char* MetatableName);

        static FClassDesc* RegisterReflectedType(UStruct* Type);

        static bool StaticUnregister(UStruct* Type);

        static UField* LoadReflectedType(const char* InName);

        static void Cleanup();
        
        bool PushMetatable(lua_State* L, const char* MetatableName);

        bool TrySetMetatable(lua_State* L, const char* MetatableName);

        bool Register(const char* MetatableName);

        bool Register(const UStruct* Class);

    private:
        static FClassDesc* RegisterInternal(UStruct* Type, const FString& Name);

        static TMap<UStruct*, FClassDesc*> Classes;
        static TMap<FName, FClassDesc*> Name2Classes;

        lua_State* GL;
    };
}