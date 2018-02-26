// The MIT License (MIT)

// Copyright 2015 Siney/Pangweiwei siney@yeah.net
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.

#include "LuaWrapper.h"

namespace slua {

	static UScriptStruct* FRotatorStruct = nullptr;
	static UScriptStruct* FTransformStruct = nullptr;
	static UScriptStruct* FLinearColorStruct = nullptr;
	static UScriptStruct* FColorStruct = nullptr;
	static UScriptStruct* FVectorStruct = nullptr;
	static UScriptStruct* FVector2DStruct = nullptr;
	static UScriptStruct* FRandomStreamStruct = nullptr;
	static UScriptStruct* FGuidStruct = nullptr;
	static UScriptStruct* FBox2DStruct = nullptr;
	static UScriptStruct* FFloatRangeBoundStruct = nullptr;
	static UScriptStruct* FFloatRangeStruct = nullptr;
	static UScriptStruct* FInt32RangeBoundStruct = nullptr;
	static UScriptStruct* FInt32RangeStruct = nullptr;
	static UScriptStruct* FFloatIntervalStruct = nullptr;
	static UScriptStruct* FInt32IntervalStruct = nullptr;
	static UScriptStruct* FPrimaryAssetTypeStruct = nullptr;
	static UScriptStruct* FPrimaryAssetIdStruct = nullptr;

	typedef void(*pushStructFunction)(lua_State* L, UStructProperty* p, uint8* parms);
	typedef void(*checkStructFunction)(lua_State* L, UStructProperty* p, uint8* parms, int i);

	TMap<UScriptStruct*, pushStructFunction> _pushStructMap;
	TMap<UScriptStruct*, checkStructFunction> _checkStructMap;

	static inline FRotator* __newFRotator() {
		return new FRotator();
	}

	static void __pushFRotator(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFRotator();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FRotator>(L, "FRotator", ptr);
	}

	static void __checkFRotator(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FRotator*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FTransform* __newFTransform() {
		return new FTransform();
	}

	static void __pushFTransform(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFTransform();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FTransform>(L, "FTransform", ptr);
	}

	static void __checkFTransform(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FTransform*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FLinearColor* __newFLinearColor() {
		return new FLinearColor();
	}

	static void __pushFLinearColor(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFLinearColor();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FLinearColor>(L, "FLinearColor", ptr);
	}

	static void __checkFLinearColor(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FLinearColor*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FColor* __newFColor() {
		return new FColor();
	}

	static void __pushFColor(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFColor();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FColor>(L, "FColor", ptr);
	}

	static void __checkFColor(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FColor*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FVector* __newFVector() {
		return new FVector();
	}

	static void __pushFVector(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFVector();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FVector>(L, "FVector", ptr);
	}

	static void __checkFVector(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FVector*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FVector2D* __newFVector2D() {
		return new FVector2D();
	}

	static void __pushFVector2D(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFVector2D();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FVector2D>(L, "FVector2D", ptr);
	}

	static void __checkFVector2D(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FVector2D*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FRandomStream* __newFRandomStream() {
		return new FRandomStream();
	}

	static void __pushFRandomStream(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFRandomStream();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FRandomStream>(L, "FRandomStream", ptr);
	}

	static void __checkFRandomStream(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FRandomStream*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FGuid* __newFGuid() {
		return new FGuid();
	}

	static void __pushFGuid(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFGuid();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FGuid>(L, "FGuid", ptr);
	}

	static void __checkFGuid(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FGuid*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FBox2D* __newFBox2D() {
		return new FBox2D();
	}

	static void __pushFBox2D(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFBox2D();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FBox2D>(L, "FBox2D", ptr);
	}

	static void __checkFBox2D(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FBox2D*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FFloatRangeBound* __newFFloatRangeBound() {
		return new FFloatRangeBound();
	}

	static void __pushFFloatRangeBound(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFFloatRangeBound();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FFloatRangeBound>(L, "FFloatRangeBound", ptr);
	}

	static void __checkFFloatRangeBound(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FFloatRangeBound*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FFloatRange* __newFFloatRange() {
		return new FFloatRange();
	}

	static void __pushFFloatRange(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFFloatRange();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FFloatRange>(L, "FFloatRange", ptr);
	}

	static void __checkFFloatRange(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FFloatRange*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FInt32RangeBound* __newFInt32RangeBound() {
		return new FInt32RangeBound();
	}

	static void __pushFInt32RangeBound(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFInt32RangeBound();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FInt32RangeBound>(L, "FInt32RangeBound", ptr);
	}

	static void __checkFInt32RangeBound(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FInt32RangeBound*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FInt32Range* __newFInt32Range() {
		return new FInt32Range();
	}

	static void __pushFInt32Range(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFInt32Range();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FInt32Range>(L, "FInt32Range", ptr);
	}

	static void __checkFInt32Range(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FInt32Range*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FFloatInterval* __newFFloatInterval() {
		return new FFloatInterval();
	}

	static void __pushFFloatInterval(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFFloatInterval();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FFloatInterval>(L, "FFloatInterval", ptr);
	}

	static void __checkFFloatInterval(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FFloatInterval*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FInt32Interval* __newFInt32Interval() {
		return new FInt32Interval();
	}

	static void __pushFInt32Interval(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFInt32Interval();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FInt32Interval>(L, "FInt32Interval", ptr);
	}

	static void __checkFInt32Interval(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FInt32Interval*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FPrimaryAssetType* __newFPrimaryAssetType() {
		return new FPrimaryAssetType();
	}

	static void __pushFPrimaryAssetType(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFPrimaryAssetType();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FPrimaryAssetType>(L, "FPrimaryAssetType", ptr);
	}

	static void __checkFPrimaryAssetType(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FPrimaryAssetType*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	static inline FPrimaryAssetId* __newFPrimaryAssetId() {
		return new FPrimaryAssetId();
	}

	static void __pushFPrimaryAssetId(lua_State* L, UStructProperty* p, uint8* parms) {
		auto ptr = __newFPrimaryAssetId();
		p->CopyValuesInternal(ptr, parms, 1);
		LuaObject::push<FPrimaryAssetId>(L, "FPrimaryAssetId", ptr);
	}

	static void __checkFPrimaryAssetId(lua_State* L, UStructProperty* p, uint8* parms, int i) {
		auto v = LuaObject::checkValue<FPrimaryAssetId*>(L, i);
		p->CopyValuesInternal(parms, v, 1);
	}

	struct FRotatorWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FRotator();
				LuaObject::push<FRotator>(L, "FRotator", self);
				return 1;
			}
			if (argc == 2) {
				auto InF = LuaObject::checkValue<float>(L, 2);
				auto self = new FRotator(InF);
				LuaObject::push<FRotator>(L, "FRotator", self);
				return 1;
			}
			if (argc == 4) {
				auto InPitch = LuaObject::checkValue<float>(L, 2);
				auto InYaw = LuaObject::checkValue<float>(L, 3);
				auto InRoll = LuaObject::checkValue<float>(L, 4);
				auto self = new FRotator(InPitch, InYaw, InRoll);
				LuaObject::push<FRotator>(L, "FRotator", self);
				return 1;
			}
			luaL_error(L, "call FRotator() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FRotator*>(L, 1);
			delete self;
			return 0;
		}

		static int get_Pitch(lua_State* L) {
			auto self = LuaObject::checkValue<FRotator*>(L, 1);
			LuaObject::push(L, self->Pitch);
			return 1;
		}

		static int set_Pitch(lua_State* L) {
			auto self = LuaObject::checkValue<FRotator*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->Pitch = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_Yaw(lua_State* L) {
			auto self = LuaObject::checkValue<FRotator*>(L, 1);
			LuaObject::push(L, self->Yaw);
			return 1;
		}

		static int set_Yaw(lua_State* L) {
			auto self = LuaObject::checkValue<FRotator*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->Yaw = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_Roll(lua_State* L) {
			auto self = LuaObject::checkValue<FRotator*>(L, 1);
			LuaObject::push(L, self->Roll);
			return 1;
		}

		static int set_Roll(lua_State* L) {
			auto self = LuaObject::checkValue<FRotator*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->Roll = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_ZeroRotator(lua_State* L) {
			LuaObject::push<FRotator>(L, "FRotator", &FRotator::ZeroRotator);
			return 1;
		}

		static int DiagnosticCheckNaN(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				self->DiagnosticCheckNaN();
				return 0;
			}
			if (argc == 2) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto Message = LuaObject::checkValue<const char*>(L, 2);
				auto Message2 = UTF8_TO_TCHAR(Message);
				self->DiagnosticCheckNaN(Message2);
				return 0;
			}
			luaL_error(L, "call FRotator::DiagnosticCheckNaN error, argc=%d", argc);
			return 0;
		}

		static int IsNearlyZero(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto Tolerance = LuaObject::checkValue<float>(L, 2);
				auto ret = self->IsNearlyZero(Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::IsNearlyZero error, argc=%d", argc);
			return 0;
		}

		static int IsZero(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto ret = self->IsZero();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::IsZero error, argc=%d", argc);
			return 0;
		}

		static int Equals(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto R = LuaObject::checkValue<FRotator*>(L, 2);
				auto R2 = *R;
				auto Tolerance = LuaObject::checkValue<float>(L, 3);
				auto ret = self->Equals(R2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::Equals error, argc=%d", argc);
			return 0;
		}

		static int Add(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto DeltaPitch = LuaObject::checkValue<float>(L, 2);
				auto DeltaYaw = LuaObject::checkValue<float>(L, 3);
				auto DeltaRoll = LuaObject::checkValue<float>(L, 4);
				auto ret = __newFRotator();
				*ret = self->Add(DeltaPitch, DeltaYaw, DeltaRoll);
				LuaObject::push<FRotator>(L, "FRotator", ret);
				return 1;
			}
			luaL_error(L, "call FRotator::Add error, argc=%d", argc);
			return 0;
		}

		static int GetInverse(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto ret = __newFRotator();
				*ret = self->GetInverse();
				LuaObject::push<FRotator>(L, "FRotator", ret);
				return 1;
			}
			luaL_error(L, "call FRotator::GetInverse error, argc=%d", argc);
			return 0;
		}

		static int GridSnap(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto RotGrid = LuaObject::checkValue<FRotator*>(L, 2);
				auto RotGrid2 = *RotGrid;
				auto ret = __newFRotator();
				*ret = self->GridSnap(RotGrid2);
				LuaObject::push<FRotator>(L, "FRotator", ret);
				return 1;
			}
			luaL_error(L, "call FRotator::GridSnap error, argc=%d", argc);
			return 0;
		}

		static int Vector(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto ret = __newFVector();
				*ret = self->Vector();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FRotator::Vector error, argc=%d", argc);
			return 0;
		}

		static int Euler(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto ret = __newFVector();
				*ret = self->Euler();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FRotator::Euler error, argc=%d", argc);
			return 0;
		}

		static int RotateVector(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto ret = __newFVector();
				*ret = self->RotateVector(V2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FRotator::RotateVector error, argc=%d", argc);
			return 0;
		}

		static int UnrotateVector(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto ret = __newFVector();
				*ret = self->UnrotateVector(V2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FRotator::UnrotateVector error, argc=%d", argc);
			return 0;
		}

		static int Clamp(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto ret = __newFRotator();
				*ret = self->Clamp();
				LuaObject::push<FRotator>(L, "FRotator", ret);
				return 1;
			}
			luaL_error(L, "call FRotator::Clamp error, argc=%d", argc);
			return 0;
		}

		static int GetNormalized(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto ret = __newFRotator();
				*ret = self->GetNormalized();
				LuaObject::push<FRotator>(L, "FRotator", ret);
				return 1;
			}
			luaL_error(L, "call FRotator::GetNormalized error, argc=%d", argc);
			return 0;
		}

		static int GetDenormalized(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto ret = __newFRotator();
				*ret = self->GetDenormalized();
				LuaObject::push<FRotator>(L, "FRotator", ret);
				return 1;
			}
			luaL_error(L, "call FRotator::GetDenormalized error, argc=%d", argc);
			return 0;
		}

		static int GetComponentForAxis(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto Axis = LuaObject::checkValue<int>(L, 2);
				auto Axis2 = (EAxis::Type)Axis;
				auto ret = self->GetComponentForAxis(Axis2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::GetComponentForAxis error, argc=%d", argc);
			return 0;
		}

		static int SetComponentForAxis(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto Axis = LuaObject::checkValue<int>(L, 2);
				auto Axis2 = (EAxis::Type)Axis;
				auto Component = LuaObject::checkValue<float>(L, 3);
				self->SetComponentForAxis(Axis2, Component);
				return 0;
			}
			luaL_error(L, "call FRotator::SetComponentForAxis error, argc=%d", argc);
			return 0;
		}

		static int Normalize(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				self->Normalize();
				return 0;
			}
			luaL_error(L, "call FRotator::Normalize error, argc=%d", argc);
			return 0;
		}

		static int GetWindingAndRemainder(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto Winding = LuaObject::checkValue<FRotator*>(L, 2);
				auto Winding2 = *Winding;
				auto Remainder = LuaObject::checkValue<FRotator*>(L, 3);
				auto Remainder2 = *Remainder;
				self->GetWindingAndRemainder(Winding2, Remainder2);
				LuaObject::push<FRotator>(L, "FRotator", Winding);
				LuaObject::push<FRotator>(L, "FRotator", Remainder);
				return 2;
			}
			luaL_error(L, "call FRotator::GetWindingAndRemainder error, argc=%d", argc);
			return 0;
		}

		static int ToString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto ret = self->ToString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::ToString error, argc=%d", argc);
			return 0;
		}

		static int ToCompactString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto ret = self->ToCompactString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::ToCompactString error, argc=%d", argc);
			return 0;
		}

		static int InitFromString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto InSourceString = LuaObject::checkValue<FString>(L, 2);
				auto ret = self->InitFromString(InSourceString);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::InitFromString error, argc=%d", argc);
			return 0;
		}

		static int ContainsNaN(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRotator*>(L, 1);
				auto ret = self->ContainsNaN();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::ContainsNaN error, argc=%d", argc);
			return 0;
		}

		static int ClampAxis(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Angle = LuaObject::checkValue<float>(L, 2);
				auto ret = FRotator::ClampAxis(Angle);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::ClampAxis error, argc=%d", argc);
			return 0;
		}

		static int NormalizeAxis(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Angle = LuaObject::checkValue<float>(L, 2);
				auto ret = FRotator::NormalizeAxis(Angle);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::NormalizeAxis error, argc=%d", argc);
			return 0;
		}

		static int CompressAxisToByte(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Angle = LuaObject::checkValue<float>(L, 2);
				auto ret = FRotator::CompressAxisToByte(Angle);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::CompressAxisToByte error, argc=%d", argc);
			return 0;
		}

		static int DecompressAxisFromByte(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Angle = LuaObject::checkValue<int>(L, 2);
				auto Angle2 = (unsigned short)Angle;
				auto ret = FRotator::DecompressAxisFromByte(Angle2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::DecompressAxisFromByte error, argc=%d", argc);
			return 0;
		}

		static int CompressAxisToShort(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Angle = LuaObject::checkValue<float>(L, 2);
				auto ret = FRotator::CompressAxisToShort(Angle);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::CompressAxisToShort error, argc=%d", argc);
			return 0;
		}

		static int DecompressAxisFromShort(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Angle = LuaObject::checkValue<int>(L, 2);
				auto Angle2 = (unsigned short)Angle;
				auto ret = FRotator::DecompressAxisFromShort(Angle2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRotator::DecompressAxisFromShort error, argc=%d", argc);
			return 0;
		}

		static int MakeFromEuler(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Euler = LuaObject::checkValue<FVector*>(L, 2);
				auto Euler2 = *Euler;
				auto ret = __newFRotator();
				*ret = FRotator::MakeFromEuler(Euler2);
				LuaObject::push<FRotator>(L, "FRotator", ret);
				return 1;
			}
			luaL_error(L, "call FRotator::MakeFromEuler error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FRotator");
			LuaObject::addField(L, "Pitch", get_Pitch, set_Pitch, true);
			LuaObject::addField(L, "Yaw", get_Yaw, set_Yaw, true);
			LuaObject::addField(L, "Roll", get_Roll, set_Roll, true);
			LuaObject::addField(L, "ZeroRotator", get_ZeroRotator, nullptr, false);
			LuaObject::addMethod(L, "DiagnosticCheckNaN", DiagnosticCheckNaN, true);
			LuaObject::addMethod(L, "IsNearlyZero", IsNearlyZero, true);
			LuaObject::addMethod(L, "IsZero", IsZero, true);
			LuaObject::addMethod(L, "Equals", Equals, true);
			LuaObject::addMethod(L, "Add", Add, true);
			LuaObject::addMethod(L, "GetInverse", GetInverse, true);
			LuaObject::addMethod(L, "GridSnap", GridSnap, true);
			LuaObject::addMethod(L, "Vector", Vector, true);
			LuaObject::addMethod(L, "Euler", Euler, true);
			LuaObject::addMethod(L, "RotateVector", RotateVector, true);
			LuaObject::addMethod(L, "UnrotateVector", UnrotateVector, true);
			LuaObject::addMethod(L, "Clamp", Clamp, true);
			LuaObject::addMethod(L, "GetNormalized", GetNormalized, true);
			LuaObject::addMethod(L, "GetDenormalized", GetDenormalized, true);
			LuaObject::addMethod(L, "GetComponentForAxis", GetComponentForAxis, true);
			LuaObject::addMethod(L, "SetComponentForAxis", SetComponentForAxis, true);
			LuaObject::addMethod(L, "Normalize", Normalize, true);
			LuaObject::addMethod(L, "GetWindingAndRemainder", GetWindingAndRemainder, true);
			LuaObject::addMethod(L, "ToString", ToString, true);
			LuaObject::addMethod(L, "ToCompactString", ToCompactString, true);
			LuaObject::addMethod(L, "InitFromString", InitFromString, true);
			LuaObject::addMethod(L, "ContainsNaN", ContainsNaN, true);
			LuaObject::addMethod(L, "ClampAxis", ClampAxis, false);
			LuaObject::addMethod(L, "NormalizeAxis", NormalizeAxis, false);
			LuaObject::addMethod(L, "CompressAxisToByte", CompressAxisToByte, false);
			LuaObject::addMethod(L, "DecompressAxisFromByte", DecompressAxisFromByte, false);
			LuaObject::addMethod(L, "CompressAxisToShort", CompressAxisToShort, false);
			LuaObject::addMethod(L, "DecompressAxisFromShort", DecompressAxisFromShort, false);
			LuaObject::addMethod(L, "MakeFromEuler", MakeFromEuler, false);
			LuaObject::finishType(L, "FRotator", __ctor, __gc);
		}

	};

	struct FTransformWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FTransform();
				LuaObject::push<FTransform>(L, "FTransform", self);
				return 1;
			}
			if (argc == 2) {
				auto InTranslation = LuaObject::checkValue<FVector*>(L, 2);
				auto InTranslation2 = *InTranslation;
				auto self = new FTransform(InTranslation2);
				LuaObject::push<FTransform>(L, "FTransform", self);
				return 1;
			}
			if (argc == 4) {
				auto InRotation = LuaObject::checkValue<FRotator*>(L, 2);
				auto InRotation2 = *InRotation;
				auto InTranslation = LuaObject::checkValue<FVector*>(L, 3);
				auto InTranslation2 = *InTranslation;
				auto InScale3D = LuaObject::checkValue<FVector*>(L, 4);
				auto InScale3D2 = *InScale3D;
				auto self = new FTransform(InRotation2, InTranslation2, InScale3D2);
				LuaObject::push<FTransform>(L, "FTransform", self);
				return 1;
			}
			if (argc == 5) {
				auto InX = LuaObject::checkValue<FVector*>(L, 2);
				auto InX2 = *InX;
				auto InY = LuaObject::checkValue<FVector*>(L, 3);
				auto InY2 = *InY;
				auto InZ = LuaObject::checkValue<FVector*>(L, 4);
				auto InZ2 = *InZ;
				auto InTranslation = LuaObject::checkValue<FVector*>(L, 5);
				auto InTranslation2 = *InTranslation;
				auto self = new FTransform(InX2, InY2, InZ2, InTranslation2);
				LuaObject::push<FTransform>(L, "FTransform", self);
				return 1;
			}
			luaL_error(L, "call FTransform() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FTransform*>(L, 1);
			delete self;
			return 0;
		}

		static int get_Identity(lua_State* L) {
			LuaObject::push<FTransform>(L, "FTransform", &FTransform::Identity);
			return 1;
		}

		static int DiagnosticCheckNaN_Translate(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				self->DiagnosticCheckNaN_Translate();
				return 0;
			}
			luaL_error(L, "call FTransform::DiagnosticCheckNaN_Translate error, argc=%d", argc);
			return 0;
		}

		static int DiagnosticCheckNaN_Rotate(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				self->DiagnosticCheckNaN_Rotate();
				return 0;
			}
			luaL_error(L, "call FTransform::DiagnosticCheckNaN_Rotate error, argc=%d", argc);
			return 0;
		}

		static int DiagnosticCheckNaN_Scale3D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				self->DiagnosticCheckNaN_Scale3D();
				return 0;
			}
			luaL_error(L, "call FTransform::DiagnosticCheckNaN_Scale3D error, argc=%d", argc);
			return 0;
		}

		static int DiagnosticCheckNaN_All(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				self->DiagnosticCheckNaN_All();
				return 0;
			}
			luaL_error(L, "call FTransform::DiagnosticCheckNaN_All error, argc=%d", argc);
			return 0;
		}

		static int DiagnosticCheck_IsValid(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				self->DiagnosticCheck_IsValid();
				return 0;
			}
			luaL_error(L, "call FTransform::DiagnosticCheck_IsValid error, argc=%d", argc);
			return 0;
		}

		static int DebugPrint(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				self->DebugPrint();
				return 0;
			}
			luaL_error(L, "call FTransform::DebugPrint error, argc=%d", argc);
			return 0;
		}

		static int ToHumanReadableString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = self->ToHumanReadableString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::ToHumanReadableString error, argc=%d", argc);
			return 0;
		}

		static int ToString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = self->ToString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::ToString error, argc=%d", argc);
			return 0;
		}

		static int InitFromString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto InSourceString = LuaObject::checkValue<FString>(L, 2);
				auto ret = self->InitFromString(InSourceString);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::InitFromString error, argc=%d", argc);
			return 0;
		}

		static int Inverse(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = __newFTransform();
				*ret = self->Inverse();
				LuaObject::push<FTransform>(L, "FTransform", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::Inverse error, argc=%d", argc);
			return 0;
		}

		static int Blend(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Atom1 = LuaObject::checkValue<FTransform*>(L, 2);
				auto Atom12 = *Atom1;
				auto Atom2 = LuaObject::checkValue<FTransform*>(L, 3);
				auto Atom22 = *Atom2;
				auto Alpha = LuaObject::checkValue<float>(L, 4);
				self->Blend(Atom12, Atom22, Alpha);
				return 0;
			}
			luaL_error(L, "call FTransform::Blend error, argc=%d", argc);
			return 0;
		}

		static int BlendWith(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto OtherAtom = LuaObject::checkValue<FTransform*>(L, 2);
				auto OtherAtom2 = *OtherAtom;
				auto Alpha = LuaObject::checkValue<float>(L, 3);
				self->BlendWith(OtherAtom2, Alpha);
				return 0;
			}
			luaL_error(L, "call FTransform::BlendWith error, argc=%d", argc);
			return 0;
		}

		static int ScaleTranslation(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto InScale3D = LuaObject::checkValue<FVector*>(L, 2);
				auto InScale3D2 = *InScale3D;
				self->ScaleTranslation(InScale3D2);
				return 0;
			}
			luaL_error(L, "call FTransform::ScaleTranslation error, argc=%d", argc);
			return 0;
		}

		static int RemoveScaling(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Tolerance = LuaObject::checkValue<float>(L, 2);
				self->RemoveScaling(Tolerance);
				return 0;
			}
			luaL_error(L, "call FTransform::RemoveScaling error, argc=%d", argc);
			return 0;
		}

		static int GetMaximumAxisScale(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = self->GetMaximumAxisScale();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetMaximumAxisScale error, argc=%d", argc);
			return 0;
		}

		static int GetMinimumAxisScale(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = self->GetMinimumAxisScale();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetMinimumAxisScale error, argc=%d", argc);
			return 0;
		}

		static int GetRelativeTransform(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Other = LuaObject::checkValue<FTransform*>(L, 2);
				auto Other2 = *Other;
				auto ret = __newFTransform();
				*ret = self->GetRelativeTransform(Other2);
				LuaObject::push<FTransform>(L, "FTransform", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetRelativeTransform error, argc=%d", argc);
			return 0;
		}

		static int GetRelativeTransformReverse(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Other = LuaObject::checkValue<FTransform*>(L, 2);
				auto Other2 = *Other;
				auto ret = __newFTransform();
				*ret = self->GetRelativeTransformReverse(Other2);
				LuaObject::push<FTransform>(L, "FTransform", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetRelativeTransformReverse error, argc=%d", argc);
			return 0;
		}

		static int SetToRelativeTransform(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ParentTransform = LuaObject::checkValue<FTransform*>(L, 2);
				auto ParentTransform2 = *ParentTransform;
				self->SetToRelativeTransform(ParentTransform2);
				return 0;
			}
			luaL_error(L, "call FTransform::SetToRelativeTransform error, argc=%d", argc);
			return 0;
		}

		static int TransformPosition(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto ret = __newFVector();
				*ret = self->TransformPosition(V2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::TransformPosition error, argc=%d", argc);
			return 0;
		}

		static int TransformPositionNoScale(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto ret = __newFVector();
				*ret = self->TransformPositionNoScale(V2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::TransformPositionNoScale error, argc=%d", argc);
			return 0;
		}

		static int InverseTransformPosition(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto ret = __newFVector();
				*ret = self->InverseTransformPosition(V2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::InverseTransformPosition error, argc=%d", argc);
			return 0;
		}

		static int InverseTransformPositionNoScale(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto ret = __newFVector();
				*ret = self->InverseTransformPositionNoScale(V2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::InverseTransformPositionNoScale error, argc=%d", argc);
			return 0;
		}

		static int TransformVector(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto ret = __newFVector();
				*ret = self->TransformVector(V2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::TransformVector error, argc=%d", argc);
			return 0;
		}

		static int TransformVectorNoScale(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto ret = __newFVector();
				*ret = self->TransformVectorNoScale(V2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::TransformVectorNoScale error, argc=%d", argc);
			return 0;
		}

		static int InverseTransformVector(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto ret = __newFVector();
				*ret = self->InverseTransformVector(V2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::InverseTransformVector error, argc=%d", argc);
			return 0;
		}

		static int InverseTransformVectorNoScale(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto ret = __newFVector();
				*ret = self->InverseTransformVectorNoScale(V2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::InverseTransformVectorNoScale error, argc=%d", argc);
			return 0;
		}

		static int GetScaled(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Scale = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFTransform();
				*ret = self->GetScaled(Scale);
				LuaObject::push<FTransform>(L, "FTransform", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetScaled error, argc=%d", argc);
			return 0;
		}

		static int GetScaledAxis(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto InAxis = LuaObject::checkValue<int>(L, 2);
				auto InAxis2 = (EAxis::Type)InAxis;
				auto ret = __newFVector();
				*ret = self->GetScaledAxis(InAxis2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetScaledAxis error, argc=%d", argc);
			return 0;
		}

		static int GetUnitAxis(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto InAxis = LuaObject::checkValue<int>(L, 2);
				auto InAxis2 = (EAxis::Type)InAxis;
				auto ret = __newFVector();
				*ret = self->GetUnitAxis(InAxis2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetUnitAxis error, argc=%d", argc);
			return 0;
		}

		static int Mirror(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto MirrorAxis = LuaObject::checkValue<int>(L, 2);
				auto MirrorAxis2 = (EAxis::Type)MirrorAxis;
				auto FlipAxis = LuaObject::checkValue<int>(L, 3);
				auto FlipAxis2 = (EAxis::Type)FlipAxis;
				self->Mirror(MirrorAxis2, FlipAxis2);
				return 0;
			}
			luaL_error(L, "call FTransform::Mirror error, argc=%d", argc);
			return 0;
		}

		static int GetLocation(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = __newFVector();
				*ret = self->GetLocation();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetLocation error, argc=%d", argc);
			return 0;
		}

		static int Rotator(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = __newFRotator();
				*ret = self->Rotator();
				LuaObject::push<FRotator>(L, "FRotator", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::Rotator error, argc=%d", argc);
			return 0;
		}

		static int GetDeterminant(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = self->GetDeterminant();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetDeterminant error, argc=%d", argc);
			return 0;
		}

		static int SetLocation(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Origin = LuaObject::checkValue<FVector*>(L, 2);
				auto Origin2 = *Origin;
				self->SetLocation(Origin2);
				return 0;
			}
			luaL_error(L, "call FTransform::SetLocation error, argc=%d", argc);
			return 0;
		}

		static int ContainsNaN(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = self->ContainsNaN();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::ContainsNaN error, argc=%d", argc);
			return 0;
		}

		static int IsValid(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = self->IsValid();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::IsValid error, argc=%d", argc);
			return 0;
		}

		static int RotationEquals(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Other = LuaObject::checkValue<FTransform*>(L, 2);
				auto Other2 = *Other;
				auto Tolerance = LuaObject::checkValue<float>(L, 3);
				auto ret = self->RotationEquals(Other2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::RotationEquals error, argc=%d", argc);
			return 0;
		}

		static int TranslationEquals(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Other = LuaObject::checkValue<FTransform*>(L, 2);
				auto Other2 = *Other;
				auto Tolerance = LuaObject::checkValue<float>(L, 3);
				auto ret = self->TranslationEquals(Other2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::TranslationEquals error, argc=%d", argc);
			return 0;
		}

		static int Scale3DEquals(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Other = LuaObject::checkValue<FTransform*>(L, 2);
				auto Other2 = *Other;
				auto Tolerance = LuaObject::checkValue<float>(L, 3);
				auto ret = self->Scale3DEquals(Other2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::Scale3DEquals error, argc=%d", argc);
			return 0;
		}

		static int Equals(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Other = LuaObject::checkValue<FTransform*>(L, 2);
				auto Other2 = *Other;
				auto Tolerance = LuaObject::checkValue<float>(L, 3);
				auto ret = self->Equals(Other2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::Equals error, argc=%d", argc);
			return 0;
		}

		static int EqualsNoScale(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Other = LuaObject::checkValue<FTransform*>(L, 2);
				auto Other2 = *Other;
				auto Tolerance = LuaObject::checkValue<float>(L, 3);
				auto ret = self->EqualsNoScale(Other2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::EqualsNoScale error, argc=%d", argc);
			return 0;
		}

		static int SetIdentity(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				self->SetIdentity();
				return 0;
			}
			luaL_error(L, "call FTransform::SetIdentity error, argc=%d", argc);
			return 0;
		}

		static int MultiplyScale3D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Scale3DMultiplier = LuaObject::checkValue<FVector*>(L, 2);
				auto Scale3DMultiplier2 = *Scale3DMultiplier;
				self->MultiplyScale3D(Scale3DMultiplier2);
				return 0;
			}
			luaL_error(L, "call FTransform::MultiplyScale3D error, argc=%d", argc);
			return 0;
		}

		static int SetTranslation(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto NewTranslation = LuaObject::checkValue<FVector*>(L, 2);
				auto NewTranslation2 = *NewTranslation;
				self->SetTranslation(NewTranslation2);
				return 0;
			}
			luaL_error(L, "call FTransform::SetTranslation error, argc=%d", argc);
			return 0;
		}

		static int CopyTranslation(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Other = LuaObject::checkValue<FTransform*>(L, 2);
				auto Other2 = *Other;
				self->CopyTranslation(Other2);
				return 0;
			}
			luaL_error(L, "call FTransform::CopyTranslation error, argc=%d", argc);
			return 0;
		}

		static int AddToTranslation(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto DeltaTranslation = LuaObject::checkValue<FVector*>(L, 2);
				auto DeltaTranslation2 = *DeltaTranslation;
				self->AddToTranslation(DeltaTranslation2);
				return 0;
			}
			luaL_error(L, "call FTransform::AddToTranslation error, argc=%d", argc);
			return 0;
		}

		static int CopyRotation(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Other = LuaObject::checkValue<FTransform*>(L, 2);
				auto Other2 = *Other;
				self->CopyRotation(Other2);
				return 0;
			}
			luaL_error(L, "call FTransform::CopyRotation error, argc=%d", argc);
			return 0;
		}

		static int SetScale3D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto NewScale3D = LuaObject::checkValue<FVector*>(L, 2);
				auto NewScale3D2 = *NewScale3D;
				self->SetScale3D(NewScale3D2);
				return 0;
			}
			luaL_error(L, "call FTransform::SetScale3D error, argc=%d", argc);
			return 0;
		}

		static int CopyScale3D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto Other = LuaObject::checkValue<FTransform*>(L, 2);
				auto Other2 = *Other;
				self->CopyScale3D(Other2);
				return 0;
			}
			luaL_error(L, "call FTransform::CopyScale3D error, argc=%d", argc);
			return 0;
		}

		static int SetTranslationAndScale3D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto NewTranslation = LuaObject::checkValue<FVector*>(L, 2);
				auto NewTranslation2 = *NewTranslation;
				auto NewScale3D = LuaObject::checkValue<FVector*>(L, 3);
				auto NewScale3D2 = *NewScale3D;
				self->SetTranslationAndScale3D(NewTranslation2, NewScale3D2);
				return 0;
			}
			luaL_error(L, "call FTransform::SetTranslationAndScale3D error, argc=%d", argc);
			return 0;
		}

		static int NormalizeRotation(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				self->NormalizeRotation();
				return 0;
			}
			luaL_error(L, "call FTransform::NormalizeRotation error, argc=%d", argc);
			return 0;
		}

		static int IsRotationNormalized(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = self->IsRotationNormalized();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::IsRotationNormalized error, argc=%d", argc);
			return 0;
		}

		static int GetTranslation(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = __newFVector();
				*ret = self->GetTranslation();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetTranslation error, argc=%d", argc);
			return 0;
		}

		static int GetScale3D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto ret = __newFVector();
				*ret = self->GetScale3D();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetScale3D error, argc=%d", argc);
			return 0;
		}

		static int CopyRotationPart(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto SrcBA = LuaObject::checkValue<FTransform*>(L, 2);
				auto SrcBA2 = *SrcBA;
				self->CopyRotationPart(SrcBA2);
				return 0;
			}
			luaL_error(L, "call FTransform::CopyRotationPart error, argc=%d", argc);
			return 0;
		}

		static int CopyTranslationAndScale3D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FTransform*>(L, 1);
				auto SrcBA = LuaObject::checkValue<FTransform*>(L, 2);
				auto SrcBA2 = *SrcBA;
				self->CopyTranslationAndScale3D(SrcBA2);
				return 0;
			}
			luaL_error(L, "call FTransform::CopyTranslationAndScale3D error, argc=%d", argc);
			return 0;
		}

		static int AnyHasNegativeScale(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto InScale3D = LuaObject::checkValue<FVector*>(L, 2);
				auto InScale3D2 = *InScale3D;
				auto InOtherScale3D = LuaObject::checkValue<FVector*>(L, 3);
				auto InOtherScale3D2 = *InOtherScale3D;
				auto ret = FTransform::AnyHasNegativeScale(InScale3D2, InOtherScale3D2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::AnyHasNegativeScale error, argc=%d", argc);
			return 0;
		}

		static int GetSafeScaleReciprocal(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto InScale = LuaObject::checkValue<FVector*>(L, 2);
				auto InScale2 = *InScale;
				auto Tolerance = LuaObject::checkValue<float>(L, 3);
				auto ret = __newFVector();
				*ret = FTransform::GetSafeScaleReciprocal(InScale2, Tolerance);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::GetSafeScaleReciprocal error, argc=%d", argc);
			return 0;
		}

		static int AreRotationsEqual(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto A = LuaObject::checkValue<FTransform*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FTransform*>(L, 3);
				auto B2 = *B;
				auto Tolerance = LuaObject::checkValue<float>(L, 4);
				auto ret = FTransform::AreRotationsEqual(A2, B2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::AreRotationsEqual error, argc=%d", argc);
			return 0;
		}

		static int AreTranslationsEqual(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto A = LuaObject::checkValue<FTransform*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FTransform*>(L, 3);
				auto B2 = *B;
				auto Tolerance = LuaObject::checkValue<float>(L, 4);
				auto ret = FTransform::AreTranslationsEqual(A2, B2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::AreTranslationsEqual error, argc=%d", argc);
			return 0;
		}

		static int AreScale3DsEqual(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto A = LuaObject::checkValue<FTransform*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FTransform*>(L, 3);
				auto B2 = *B;
				auto Tolerance = LuaObject::checkValue<float>(L, 4);
				auto ret = FTransform::AreScale3DsEqual(A2, B2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FTransform::AreScale3DsEqual error, argc=%d", argc);
			return 0;
		}

		static int AddTranslations(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FTransform*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FTransform*>(L, 3);
				auto B2 = *B;
				auto ret = __newFVector();
				*ret = FTransform::AddTranslations(A2, B2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::AddTranslations error, argc=%d", argc);
			return 0;
		}

		static int SubtractTranslations(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FTransform*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FTransform*>(L, 3);
				auto B2 = *B;
				auto ret = __newFVector();
				*ret = FTransform::SubtractTranslations(A2, B2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FTransform::SubtractTranslations error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FTransform");
			LuaObject::addField(L, "Identity", get_Identity, nullptr, false);
			LuaObject::addMethod(L, "DiagnosticCheckNaN_Translate", DiagnosticCheckNaN_Translate, true);
			LuaObject::addMethod(L, "DiagnosticCheckNaN_Rotate", DiagnosticCheckNaN_Rotate, true);
			LuaObject::addMethod(L, "DiagnosticCheckNaN_Scale3D", DiagnosticCheckNaN_Scale3D, true);
			LuaObject::addMethod(L, "DiagnosticCheckNaN_All", DiagnosticCheckNaN_All, true);
			LuaObject::addMethod(L, "DiagnosticCheck_IsValid", DiagnosticCheck_IsValid, true);
			LuaObject::addMethod(L, "DebugPrint", DebugPrint, true);
			LuaObject::addMethod(L, "ToHumanReadableString", ToHumanReadableString, true);
			LuaObject::addMethod(L, "ToString", ToString, true);
			LuaObject::addMethod(L, "InitFromString", InitFromString, true);
			LuaObject::addMethod(L, "Inverse", Inverse, true);
			LuaObject::addMethod(L, "Blend", Blend, true);
			LuaObject::addMethod(L, "BlendWith", BlendWith, true);
			LuaObject::addMethod(L, "ScaleTranslation", ScaleTranslation, true);
			LuaObject::addMethod(L, "RemoveScaling", RemoveScaling, true);
			LuaObject::addMethod(L, "GetMaximumAxisScale", GetMaximumAxisScale, true);
			LuaObject::addMethod(L, "GetMinimumAxisScale", GetMinimumAxisScale, true);
			LuaObject::addMethod(L, "GetRelativeTransform", GetRelativeTransform, true);
			LuaObject::addMethod(L, "GetRelativeTransformReverse", GetRelativeTransformReverse, true);
			LuaObject::addMethod(L, "SetToRelativeTransform", SetToRelativeTransform, true);
			LuaObject::addMethod(L, "TransformPosition", TransformPosition, true);
			LuaObject::addMethod(L, "TransformPositionNoScale", TransformPositionNoScale, true);
			LuaObject::addMethod(L, "InverseTransformPosition", InverseTransformPosition, true);
			LuaObject::addMethod(L, "InverseTransformPositionNoScale", InverseTransformPositionNoScale, true);
			LuaObject::addMethod(L, "TransformVector", TransformVector, true);
			LuaObject::addMethod(L, "TransformVectorNoScale", TransformVectorNoScale, true);
			LuaObject::addMethod(L, "InverseTransformVector", InverseTransformVector, true);
			LuaObject::addMethod(L, "InverseTransformVectorNoScale", InverseTransformVectorNoScale, true);
			LuaObject::addMethod(L, "GetScaled", GetScaled, true);
			LuaObject::addMethod(L, "GetScaledAxis", GetScaledAxis, true);
			LuaObject::addMethod(L, "GetUnitAxis", GetUnitAxis, true);
			LuaObject::addMethod(L, "Mirror", Mirror, true);
			LuaObject::addMethod(L, "GetLocation", GetLocation, true);
			LuaObject::addMethod(L, "Rotator", Rotator, true);
			LuaObject::addMethod(L, "GetDeterminant", GetDeterminant, true);
			LuaObject::addMethod(L, "SetLocation", SetLocation, true);
			LuaObject::addMethod(L, "ContainsNaN", ContainsNaN, true);
			LuaObject::addMethod(L, "IsValid", IsValid, true);
			LuaObject::addMethod(L, "RotationEquals", RotationEquals, true);
			LuaObject::addMethod(L, "TranslationEquals", TranslationEquals, true);
			LuaObject::addMethod(L, "Scale3DEquals", Scale3DEquals, true);
			LuaObject::addMethod(L, "Equals", Equals, true);
			LuaObject::addMethod(L, "EqualsNoScale", EqualsNoScale, true);
			LuaObject::addMethod(L, "SetIdentity", SetIdentity, true);
			LuaObject::addMethod(L, "MultiplyScale3D", MultiplyScale3D, true);
			LuaObject::addMethod(L, "SetTranslation", SetTranslation, true);
			LuaObject::addMethod(L, "CopyTranslation", CopyTranslation, true);
			LuaObject::addMethod(L, "AddToTranslation", AddToTranslation, true);
			LuaObject::addMethod(L, "CopyRotation", CopyRotation, true);
			LuaObject::addMethod(L, "SetScale3D", SetScale3D, true);
			LuaObject::addMethod(L, "CopyScale3D", CopyScale3D, true);
			LuaObject::addMethod(L, "SetTranslationAndScale3D", SetTranslationAndScale3D, true);
			LuaObject::addMethod(L, "NormalizeRotation", NormalizeRotation, true);
			LuaObject::addMethod(L, "IsRotationNormalized", IsRotationNormalized, true);
			LuaObject::addMethod(L, "GetTranslation", GetTranslation, true);
			LuaObject::addMethod(L, "GetScale3D", GetScale3D, true);
			LuaObject::addMethod(L, "CopyRotationPart", CopyRotationPart, true);
			LuaObject::addMethod(L, "CopyTranslationAndScale3D", CopyTranslationAndScale3D, true);
			LuaObject::addMethod(L, "AnyHasNegativeScale", AnyHasNegativeScale, false);
			LuaObject::addMethod(L, "GetSafeScaleReciprocal", GetSafeScaleReciprocal, false);
			LuaObject::addMethod(L, "AreRotationsEqual", AreRotationsEqual, false);
			LuaObject::addMethod(L, "AreTranslationsEqual", AreTranslationsEqual, false);
			LuaObject::addMethod(L, "AreScale3DsEqual", AreScale3DsEqual, false);
			LuaObject::addMethod(L, "AddTranslations", AddTranslations, false);
			LuaObject::addMethod(L, "SubtractTranslations", SubtractTranslations, false);
			LuaObject::finishType(L, "FTransform", __ctor, __gc);
		}

	};

	struct FLinearColorWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FLinearColor();
				LuaObject::push<FLinearColor>(L, "FLinearColor", self);
				return 1;
			}
			if (argc == 2) {
				auto _a0 = LuaObject::checkValue<int>(L, 2);
				auto _a02 = (EForceInit)_a0;
				auto self = new FLinearColor(_a02);
				LuaObject::push<FLinearColor>(L, "FLinearColor", self);
				return 1;
			}
			if (argc == 5) {
				auto InR = LuaObject::checkValue<float>(L, 2);
				auto InG = LuaObject::checkValue<float>(L, 3);
				auto InB = LuaObject::checkValue<float>(L, 4);
				auto InA = LuaObject::checkValue<float>(L, 5);
				auto self = new FLinearColor(InR, InG, InB, InA);
				LuaObject::push<FLinearColor>(L, "FLinearColor", self);
				return 1;
			}
			luaL_error(L, "call FLinearColor() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
			delete self;
			return 0;
		}

		static int get_R(lua_State* L) {
			auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
			LuaObject::push(L, self->R);
			return 1;
		}

		static int set_R(lua_State* L) {
			auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->R = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_G(lua_State* L) {
			auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
			LuaObject::push(L, self->G);
			return 1;
		}

		static int set_G(lua_State* L) {
			auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->G = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_B(lua_State* L) {
			auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
			LuaObject::push(L, self->B);
			return 1;
		}

		static int set_B(lua_State* L) {
			auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->B = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_A(lua_State* L) {
			auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
			LuaObject::push(L, self->A);
			return 1;
		}

		static int set_A(lua_State* L) {
			auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->A = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_White(lua_State* L) {
			LuaObject::push<FLinearColor>(L, "FLinearColor", &FLinearColor::White);
			return 1;
		}

		static int get_Gray(lua_State* L) {
			LuaObject::push<FLinearColor>(L, "FLinearColor", &FLinearColor::Gray);
			return 1;
		}

		static int get_Black(lua_State* L) {
			LuaObject::push<FLinearColor>(L, "FLinearColor", &FLinearColor::Black);
			return 1;
		}

		static int get_Transparent(lua_State* L) {
			LuaObject::push<FLinearColor>(L, "FLinearColor", &FLinearColor::Transparent);
			return 1;
		}

		static int get_Red(lua_State* L) {
			LuaObject::push<FLinearColor>(L, "FLinearColor", &FLinearColor::Red);
			return 1;
		}

		static int get_Green(lua_State* L) {
			LuaObject::push<FLinearColor>(L, "FLinearColor", &FLinearColor::Green);
			return 1;
		}

		static int get_Blue(lua_State* L) {
			LuaObject::push<FLinearColor>(L, "FLinearColor", &FLinearColor::Blue);
			return 1;
		}

		static int get_Yellow(lua_State* L) {
			LuaObject::push<FLinearColor>(L, "FLinearColor", &FLinearColor::Yellow);
			return 1;
		}

		static int ToRGBE(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ret = __newFColor();
				*ret = self->ToRGBE();
				LuaObject::push<FColor>(L, "FColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::ToRGBE error, argc=%d", argc);
			return 0;
		}

		static int Component(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto Index = LuaObject::checkValue<int>(L, 2);
				auto ret = self->Component(Index);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::Component error, argc=%d", argc);
			return 0;
		}

		static int GetClamped(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto InMin = LuaObject::checkValue<float>(L, 2);
				auto InMax = LuaObject::checkValue<float>(L, 3);
				auto ret = __newFLinearColor();
				*ret = self->GetClamped(InMin, InMax);
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::GetClamped error, argc=%d", argc);
			return 0;
		}

		static int Equals(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ColorB = LuaObject::checkValue<FLinearColor*>(L, 2);
				auto ColorB2 = *ColorB;
				auto Tolerance = LuaObject::checkValue<float>(L, 3);
				auto ret = self->Equals(ColorB2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::Equals error, argc=%d", argc);
			return 0;
		}

		static int CopyWithNewOpacity(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto NewOpacicty = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFLinearColor();
				*ret = self->CopyWithNewOpacity(NewOpacicty);
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::CopyWithNewOpacity error, argc=%d", argc);
			return 0;
		}

		static int LinearRGBToHSV(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ret = __newFLinearColor();
				*ret = self->LinearRGBToHSV();
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::LinearRGBToHSV error, argc=%d", argc);
			return 0;
		}

		static int HSVToLinearRGB(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ret = __newFLinearColor();
				*ret = self->HSVToLinearRGB();
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::HSVToLinearRGB error, argc=%d", argc);
			return 0;
		}

		static int Quantize(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ret = __newFColor();
				*ret = self->Quantize();
				LuaObject::push<FColor>(L, "FColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::Quantize error, argc=%d", argc);
			return 0;
		}

		static int QuantizeRound(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ret = __newFColor();
				*ret = self->QuantizeRound();
				LuaObject::push<FColor>(L, "FColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::QuantizeRound error, argc=%d", argc);
			return 0;
		}

		static int ToFColor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto bSRGB = LuaObject::checkValue<bool>(L, 2);
				auto bSRGB2 = (const bool)bSRGB;
				auto ret = __newFColor();
				*ret = self->ToFColor(bSRGB2);
				LuaObject::push<FColor>(L, "FColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::ToFColor error, argc=%d", argc);
			return 0;
		}

		static int Desaturate(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto Desaturation = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFLinearColor();
				*ret = self->Desaturate(Desaturation);
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::Desaturate error, argc=%d", argc);
			return 0;
		}

		static int ComputeLuminance(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ret = self->ComputeLuminance();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::ComputeLuminance error, argc=%d", argc);
			return 0;
		}

		static int GetMax(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ret = self->GetMax();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::GetMax error, argc=%d", argc);
			return 0;
		}

		static int IsAlmostBlack(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ret = self->IsAlmostBlack();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::IsAlmostBlack error, argc=%d", argc);
			return 0;
		}

		static int GetMin(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ret = self->GetMin();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::GetMin error, argc=%d", argc);
			return 0;
		}

		static int GetLuminance(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ret = self->GetLuminance();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::GetLuminance error, argc=%d", argc);
			return 0;
		}

		static int ToString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto ret = self->ToString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::ToString error, argc=%d", argc);
			return 0;
		}

		static int InitFromString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FLinearColor*>(L, 1);
				auto InSourceString = LuaObject::checkValue<FString>(L, 2);
				auto ret = self->InitFromString(InSourceString);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::InitFromString error, argc=%d", argc);
			return 0;
		}

		static int FromSRGBColor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Color = LuaObject::checkValue<FColor*>(L, 2);
				auto Color2 = *Color;
				auto ret = __newFLinearColor();
				*ret = FLinearColor::FromSRGBColor(Color2);
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::FromSRGBColor error, argc=%d", argc);
			return 0;
		}

		static int FromPow22Color(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Color = LuaObject::checkValue<FColor*>(L, 2);
				auto Color2 = *Color;
				auto ret = __newFLinearColor();
				*ret = FLinearColor::FromPow22Color(Color2);
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::FromPow22Color error, argc=%d", argc);
			return 0;
		}

		static int FGetHSV(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto H = LuaObject::checkValue<int>(L, 2);
				auto H2 = (unsigned char)H;
				auto S = LuaObject::checkValue<int>(L, 3);
				auto S2 = (unsigned char)S;
				auto V = LuaObject::checkValue<int>(L, 4);
				auto V2 = (unsigned char)V;
				auto ret = __newFLinearColor();
				*ret = FLinearColor::FGetHSV(H2, S2, V2);
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::FGetHSV error, argc=%d", argc);
			return 0;
		}

		static int MakeRandomColor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto ret = __newFLinearColor();
				*ret = FLinearColor::MakeRandomColor();
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::MakeRandomColor error, argc=%d", argc);
			return 0;
		}

		static int MakeFromColorTemperature(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Temp = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFLinearColor();
				*ret = FLinearColor::MakeFromColorTemperature(Temp);
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::MakeFromColorTemperature error, argc=%d", argc);
			return 0;
		}

		static int Dist(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto V1 = LuaObject::checkValue<FLinearColor*>(L, 2);
				auto V12 = *V1;
				auto V2 = LuaObject::checkValue<FLinearColor*>(L, 3);
				auto V22 = *V2;
				auto ret = FLinearColor::Dist(V12, V22);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::Dist error, argc=%d", argc);
			return 0;
		}

		static int LerpUsingHSV(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto From = LuaObject::checkValue<FLinearColor*>(L, 2);
				auto From2 = *From;
				auto To = LuaObject::checkValue<FLinearColor*>(L, 3);
				auto To2 = *To;
				auto Progress = LuaObject::checkValue<float>(L, 4);
				auto Progress2 = (const float)Progress;
				auto ret = __newFLinearColor();
				*ret = FLinearColor::LerpUsingHSV(From2, To2, Progress2);
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FLinearColor::LerpUsingHSV error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FLinearColor");
			LuaObject::addField(L, "R", get_R, set_R, true);
			LuaObject::addField(L, "G", get_G, set_G, true);
			LuaObject::addField(L, "B", get_B, set_B, true);
			LuaObject::addField(L, "A", get_A, set_A, true);
			LuaObject::addField(L, "White", get_White, nullptr, false);
			LuaObject::addField(L, "Gray", get_Gray, nullptr, false);
			LuaObject::addField(L, "Black", get_Black, nullptr, false);
			LuaObject::addField(L, "Transparent", get_Transparent, nullptr, false);
			LuaObject::addField(L, "Red", get_Red, nullptr, false);
			LuaObject::addField(L, "Green", get_Green, nullptr, false);
			LuaObject::addField(L, "Blue", get_Blue, nullptr, false);
			LuaObject::addField(L, "Yellow", get_Yellow, nullptr, false);
			LuaObject::addMethod(L, "ToRGBE", ToRGBE, true);
			LuaObject::addMethod(L, "Component", Component, true);
			LuaObject::addMethod(L, "GetClamped", GetClamped, true);
			LuaObject::addMethod(L, "Equals", Equals, true);
			LuaObject::addMethod(L, "CopyWithNewOpacity", CopyWithNewOpacity, true);
			LuaObject::addMethod(L, "LinearRGBToHSV", LinearRGBToHSV, true);
			LuaObject::addMethod(L, "HSVToLinearRGB", HSVToLinearRGB, true);
			LuaObject::addMethod(L, "Quantize", Quantize, true);
			LuaObject::addMethod(L, "QuantizeRound", QuantizeRound, true);
			LuaObject::addMethod(L, "ToFColor", ToFColor, true);
			LuaObject::addMethod(L, "Desaturate", Desaturate, true);
			LuaObject::addMethod(L, "ComputeLuminance", ComputeLuminance, true);
			LuaObject::addMethod(L, "GetMax", GetMax, true);
			LuaObject::addMethod(L, "IsAlmostBlack", IsAlmostBlack, true);
			LuaObject::addMethod(L, "GetMin", GetMin, true);
			LuaObject::addMethod(L, "GetLuminance", GetLuminance, true);
			LuaObject::addMethod(L, "ToString", ToString, true);
			LuaObject::addMethod(L, "InitFromString", InitFromString, true);
			LuaObject::addMethod(L, "FromSRGBColor", FromSRGBColor, false);
			LuaObject::addMethod(L, "FromPow22Color", FromPow22Color, false);
			LuaObject::addMethod(L, "FGetHSV", FGetHSV, false);
			LuaObject::addMethod(L, "MakeRandomColor", MakeRandomColor, false);
			LuaObject::addMethod(L, "MakeFromColorTemperature", MakeFromColorTemperature, false);
			LuaObject::addMethod(L, "Dist", Dist, false);
			LuaObject::addMethod(L, "LerpUsingHSV", LerpUsingHSV, false);
			LuaObject::finishType(L, "FLinearColor", __ctor, __gc);
		}

	};

	struct FColorWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FColor();
				LuaObject::push<FColor>(L, "FColor", self);
				return 1;
			}
			if (argc == 2) {
				auto _a0 = LuaObject::checkValue<int>(L, 2);
				auto _a02 = (EForceInit)_a0;
				auto self = new FColor(_a02);
				LuaObject::push<FColor>(L, "FColor", self);
				return 1;
			}
			if (argc == 5) {
				auto InR = LuaObject::checkValue<int>(L, 2);
				auto InR2 = (unsigned char)InR;
				auto InG = LuaObject::checkValue<int>(L, 3);
				auto InG2 = (unsigned char)InG;
				auto InB = LuaObject::checkValue<int>(L, 4);
				auto InB2 = (unsigned char)InB;
				auto InA = LuaObject::checkValue<int>(L, 5);
				auto InA2 = (unsigned char)InA;
				auto self = new FColor(InR2, InG2, InB2, InA2);
				LuaObject::push<FColor>(L, "FColor", self);
				return 1;
			}
			luaL_error(L, "call FColor() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FColor*>(L, 1);
			delete self;
			return 0;
		}

		static int get_White(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::White);
			return 1;
		}

		static int get_Black(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Black);
			return 1;
		}

		static int get_Transparent(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Transparent);
			return 1;
		}

		static int get_Red(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Red);
			return 1;
		}

		static int get_Green(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Green);
			return 1;
		}

		static int get_Blue(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Blue);
			return 1;
		}

		static int get_Yellow(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Yellow);
			return 1;
		}

		static int get_Cyan(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Cyan);
			return 1;
		}

		static int get_Magenta(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Magenta);
			return 1;
		}

		static int get_Orange(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Orange);
			return 1;
		}

		static int get_Purple(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Purple);
			return 1;
		}

		static int get_Turquoise(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Turquoise);
			return 1;
		}

		static int get_Silver(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Silver);
			return 1;
		}

		static int get_Emerald(lua_State* L) {
			LuaObject::push<FColor>(L, "FColor", &FColor::Emerald);
			return 1;
		}

		static int DWColor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FColor*>(L, 1);
				auto ret = self->DWColor();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FColor::DWColor error, argc=%d", argc);
			return 0;
		}

		static int FromRGBE(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FColor*>(L, 1);
				auto ret = __newFLinearColor();
				*ret = self->FromRGBE();
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FColor::FromRGBE error, argc=%d", argc);
			return 0;
		}

		static int WithAlpha(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FColor*>(L, 1);
				auto Alpha = LuaObject::checkValue<int>(L, 2);
				auto Alpha2 = (unsigned char)Alpha;
				auto ret = __newFColor();
				*ret = self->WithAlpha(Alpha2);
				LuaObject::push<FColor>(L, "FColor", ret);
				return 1;
			}
			luaL_error(L, "call FColor::WithAlpha error, argc=%d", argc);
			return 0;
		}

		static int ReinterpretAsLinear(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FColor*>(L, 1);
				auto ret = __newFLinearColor();
				*ret = self->ReinterpretAsLinear();
				LuaObject::push<FLinearColor>(L, "FLinearColor", ret);
				return 1;
			}
			luaL_error(L, "call FColor::ReinterpretAsLinear error, argc=%d", argc);
			return 0;
		}

		static int ToHex(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FColor*>(L, 1);
				auto ret = self->ToHex();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FColor::ToHex error, argc=%d", argc);
			return 0;
		}

		static int ToString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FColor*>(L, 1);
				auto ret = self->ToString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FColor::ToString error, argc=%d", argc);
			return 0;
		}

		static int InitFromString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FColor*>(L, 1);
				auto InSourceString = LuaObject::checkValue<FString>(L, 2);
				auto ret = self->InitFromString(InSourceString);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FColor::InitFromString error, argc=%d", argc);
			return 0;
		}

		static int ToPackedARGB(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FColor*>(L, 1);
				auto ret = self->ToPackedARGB();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FColor::ToPackedARGB error, argc=%d", argc);
			return 0;
		}

		static int ToPackedABGR(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FColor*>(L, 1);
				auto ret = self->ToPackedABGR();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FColor::ToPackedABGR error, argc=%d", argc);
			return 0;
		}

		static int ToPackedRGBA(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FColor*>(L, 1);
				auto ret = self->ToPackedRGBA();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FColor::ToPackedRGBA error, argc=%d", argc);
			return 0;
		}

		static int ToPackedBGRA(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FColor*>(L, 1);
				auto ret = self->ToPackedBGRA();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FColor::ToPackedBGRA error, argc=%d", argc);
			return 0;
		}

		static int FromHex(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto HexString = LuaObject::checkValue<FString>(L, 2);
				auto ret = __newFColor();
				*ret = FColor::FromHex(HexString);
				LuaObject::push<FColor>(L, "FColor", ret);
				return 1;
			}
			luaL_error(L, "call FColor::FromHex error, argc=%d", argc);
			return 0;
		}

		static int MakeRandomColor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto ret = __newFColor();
				*ret = FColor::MakeRandomColor();
				LuaObject::push<FColor>(L, "FColor", ret);
				return 1;
			}
			luaL_error(L, "call FColor::MakeRandomColor error, argc=%d", argc);
			return 0;
		}

		static int MakeRedToGreenColorFromScalar(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Scalar = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFColor();
				*ret = FColor::MakeRedToGreenColorFromScalar(Scalar);
				LuaObject::push<FColor>(L, "FColor", ret);
				return 1;
			}
			luaL_error(L, "call FColor::MakeRedToGreenColorFromScalar error, argc=%d", argc);
			return 0;
		}

		static int MakeFromColorTemperature(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Temp = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFColor();
				*ret = FColor::MakeFromColorTemperature(Temp);
				LuaObject::push<FColor>(L, "FColor", ret);
				return 1;
			}
			luaL_error(L, "call FColor::MakeFromColorTemperature error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FColor");
			LuaObject::addField(L, "White", get_White, nullptr, false);
			LuaObject::addField(L, "Black", get_Black, nullptr, false);
			LuaObject::addField(L, "Transparent", get_Transparent, nullptr, false);
			LuaObject::addField(L, "Red", get_Red, nullptr, false);
			LuaObject::addField(L, "Green", get_Green, nullptr, false);
			LuaObject::addField(L, "Blue", get_Blue, nullptr, false);
			LuaObject::addField(L, "Yellow", get_Yellow, nullptr, false);
			LuaObject::addField(L, "Cyan", get_Cyan, nullptr, false);
			LuaObject::addField(L, "Magenta", get_Magenta, nullptr, false);
			LuaObject::addField(L, "Orange", get_Orange, nullptr, false);
			LuaObject::addField(L, "Purple", get_Purple, nullptr, false);
			LuaObject::addField(L, "Turquoise", get_Turquoise, nullptr, false);
			LuaObject::addField(L, "Silver", get_Silver, nullptr, false);
			LuaObject::addField(L, "Emerald", get_Emerald, nullptr, false);
			LuaObject::addMethod(L, "DWColor", DWColor, true);
			LuaObject::addMethod(L, "FromRGBE", FromRGBE, true);
			LuaObject::addMethod(L, "WithAlpha", WithAlpha, true);
			LuaObject::addMethod(L, "ReinterpretAsLinear", ReinterpretAsLinear, true);
			LuaObject::addMethod(L, "ToHex", ToHex, true);
			LuaObject::addMethod(L, "ToString", ToString, true);
			LuaObject::addMethod(L, "InitFromString", InitFromString, true);
			LuaObject::addMethod(L, "ToPackedARGB", ToPackedARGB, true);
			LuaObject::addMethod(L, "ToPackedABGR", ToPackedABGR, true);
			LuaObject::addMethod(L, "ToPackedRGBA", ToPackedRGBA, true);
			LuaObject::addMethod(L, "ToPackedBGRA", ToPackedBGRA, true);
			LuaObject::addMethod(L, "FromHex", FromHex, false);
			LuaObject::addMethod(L, "MakeRandomColor", MakeRandomColor, false);
			LuaObject::addMethod(L, "MakeRedToGreenColorFromScalar", MakeRedToGreenColorFromScalar, false);
			LuaObject::addMethod(L, "MakeFromColorTemperature", MakeFromColorTemperature, false);
			LuaObject::finishType(L, "FColor", __ctor, __gc);
		}

	};

	struct FVectorWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FVector();
				LuaObject::push<FVector>(L, "FVector", self);
				return 1;
			}
			if (argc == 2) {
				auto InF = LuaObject::checkValue<float>(L, 2);
				auto self = new FVector(InF);
				LuaObject::push<FVector>(L, "FVector", self);
				return 1;
			}
			if (argc == 3) {
				auto V = LuaObject::checkValue<FVector2D*>(L, 2);
				auto V2 = *V;
				auto InZ = LuaObject::checkValue<float>(L, 3);
				auto self = new FVector(V2, InZ);
				LuaObject::push<FVector>(L, "FVector", self);
				return 1;
			}
			if (argc == 4) {
				auto InX = LuaObject::checkValue<float>(L, 2);
				auto InY = LuaObject::checkValue<float>(L, 3);
				auto InZ = LuaObject::checkValue<float>(L, 4);
				auto self = new FVector(InX, InY, InZ);
				LuaObject::push<FVector>(L, "FVector", self);
				return 1;
			}
			luaL_error(L, "call FVector() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FVector*>(L, 1);
			delete self;
			return 0;
		}

		static int get_X(lua_State* L) {
			auto self = LuaObject::checkValue<FVector*>(L, 1);
			LuaObject::push(L, self->X);
			return 1;
		}

		static int set_X(lua_State* L) {
			auto self = LuaObject::checkValue<FVector*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->X = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_Y(lua_State* L) {
			auto self = LuaObject::checkValue<FVector*>(L, 1);
			LuaObject::push(L, self->Y);
			return 1;
		}

		static int set_Y(lua_State* L) {
			auto self = LuaObject::checkValue<FVector*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->Y = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_Z(lua_State* L) {
			auto self = LuaObject::checkValue<FVector*>(L, 1);
			LuaObject::push(L, self->Z);
			return 1;
		}

		static int set_Z(lua_State* L) {
			auto self = LuaObject::checkValue<FVector*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->Z = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_ZeroVector(lua_State* L) {
			LuaObject::push<FVector>(L, "FVector", &FVector::ZeroVector);
			return 1;
		}

		static int get_OneVector(lua_State* L) {
			LuaObject::push<FVector>(L, "FVector", &FVector::OneVector);
			return 1;
		}

		static int get_UpVector(lua_State* L) {
			LuaObject::push<FVector>(L, "FVector", &FVector::UpVector);
			return 1;
		}

		static int get_ForwardVector(lua_State* L) {
			LuaObject::push<FVector>(L, "FVector", &FVector::ForwardVector);
			return 1;
		}

		static int get_RightVector(lua_State* L) {
			LuaObject::push<FVector>(L, "FVector", &FVector::RightVector);
			return 1;
		}

		static int DiagnosticCheckNaN(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				self->DiagnosticCheckNaN();
				return 0;
			}
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Message = LuaObject::checkValue<const char*>(L, 2);
				auto Message2 = UTF8_TO_TCHAR(Message);
				self->DiagnosticCheckNaN(Message2);
				return 0;
			}
			luaL_error(L, "call FVector::DiagnosticCheckNaN error, argc=%d", argc);
			return 0;
		}

		static int Equals(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto Tolerance = LuaObject::checkValue<float>(L, 3);
				auto ret = self->Equals(V2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Equals error, argc=%d", argc);
			return 0;
		}

		static int AllComponentsEqual(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Tolerance = LuaObject::checkValue<float>(L, 2);
				auto ret = self->AllComponentsEqual(Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::AllComponentsEqual error, argc=%d", argc);
			return 0;
		}

		static int Component(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Index = LuaObject::checkValue<int>(L, 2);
				auto ret = self->Component(Index);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Component error, argc=%d", argc);
			return 0;
		}

		static int GetComponentForAxis(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Axis = LuaObject::checkValue<int>(L, 2);
				auto Axis2 = (EAxis::Type)Axis;
				auto ret = self->GetComponentForAxis(Axis2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetComponentForAxis error, argc=%d", argc);
			return 0;
		}

		static int SetComponentForAxis(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Axis = LuaObject::checkValue<int>(L, 2);
				auto Axis2 = (EAxis::Type)Axis;
				auto Component = LuaObject::checkValue<float>(L, 3);
				self->SetComponentForAxis(Axis2, Component);
				return 0;
			}
			luaL_error(L, "call FVector::SetComponentForAxis error, argc=%d", argc);
			return 0;
		}

		static int Set(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto InX = LuaObject::checkValue<float>(L, 2);
				auto InY = LuaObject::checkValue<float>(L, 3);
				auto InZ = LuaObject::checkValue<float>(L, 4);
				self->Set(InX, InY, InZ);
				return 0;
			}
			luaL_error(L, "call FVector::Set error, argc=%d", argc);
			return 0;
		}

		static int GetMax(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->GetMax();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetMax error, argc=%d", argc);
			return 0;
		}

		static int GetAbsMax(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->GetAbsMax();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetAbsMax error, argc=%d", argc);
			return 0;
		}

		static int GetMin(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->GetMin();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetMin error, argc=%d", argc);
			return 0;
		}

		static int GetAbsMin(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->GetAbsMin();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetAbsMin error, argc=%d", argc);
			return 0;
		}

		static int ComponentMin(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Other = LuaObject::checkValue<FVector*>(L, 2);
				auto Other2 = *Other;
				auto ret = __newFVector();
				*ret = self->ComponentMin(Other2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::ComponentMin error, argc=%d", argc);
			return 0;
		}

		static int ComponentMax(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Other = LuaObject::checkValue<FVector*>(L, 2);
				auto Other2 = *Other;
				auto ret = __newFVector();
				*ret = self->ComponentMax(Other2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::ComponentMax error, argc=%d", argc);
			return 0;
		}

		static int GetAbs(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = __newFVector();
				*ret = self->GetAbs();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetAbs error, argc=%d", argc);
			return 0;
		}

		static int Size(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->Size();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Size error, argc=%d", argc);
			return 0;
		}

		static int SizeSquared(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->SizeSquared();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::SizeSquared error, argc=%d", argc);
			return 0;
		}

		static int Size2D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->Size2D();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Size2D error, argc=%d", argc);
			return 0;
		}

		static int SizeSquared2D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->SizeSquared2D();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::SizeSquared2D error, argc=%d", argc);
			return 0;
		}

		static int IsNearlyZero(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Tolerance = LuaObject::checkValue<float>(L, 2);
				auto ret = self->IsNearlyZero(Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::IsNearlyZero error, argc=%d", argc);
			return 0;
		}

		static int IsZero(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->IsZero();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::IsZero error, argc=%d", argc);
			return 0;
		}

		static int Normalize(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Tolerance = LuaObject::checkValue<float>(L, 2);
				auto ret = self->Normalize(Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Normalize error, argc=%d", argc);
			return 0;
		}

		static int IsNormalized(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->IsNormalized();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::IsNormalized error, argc=%d", argc);
			return 0;
		}

		static int ToDirectionAndLength(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto OutDir = LuaObject::checkValue<FVector*>(L, 2);
				auto OutDir2 = *OutDir;
				auto OutLength = LuaObject::checkValue<float>(L, 3);
				self->ToDirectionAndLength(OutDir2, OutLength);
				LuaObject::push<FVector>(L, "FVector", OutDir);
				LuaObject::push(L, OutLength);
				return 2;
			}
			luaL_error(L, "call FVector::ToDirectionAndLength error, argc=%d", argc);
			return 0;
		}

		static int GetSignVector(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = __newFVector();
				*ret = self->GetSignVector();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetSignVector error, argc=%d", argc);
			return 0;
		}

		static int Projection(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = __newFVector();
				*ret = self->Projection();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::Projection error, argc=%d", argc);
			return 0;
		}

		static int GetUnsafeNormal(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = __newFVector();
				*ret = self->GetUnsafeNormal();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetUnsafeNormal error, argc=%d", argc);
			return 0;
		}

		static int GridSnap(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto GridSz = LuaObject::checkValue<float>(L, 2);
				auto GridSz2 = (const float)GridSz;
				auto ret = __newFVector();
				*ret = self->GridSnap(GridSz2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::GridSnap error, argc=%d", argc);
			return 0;
		}

		static int BoundToCube(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Radius = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFVector();
				*ret = self->BoundToCube(Radius);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::BoundToCube error, argc=%d", argc);
			return 0;
		}

		static int GetClampedToSize(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Min = LuaObject::checkValue<float>(L, 2);
				auto Max = LuaObject::checkValue<float>(L, 3);
				auto ret = __newFVector();
				*ret = self->GetClampedToSize(Min, Max);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetClampedToSize error, argc=%d", argc);
			return 0;
		}

		static int GetClampedToSize2D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Min = LuaObject::checkValue<float>(L, 2);
				auto Max = LuaObject::checkValue<float>(L, 3);
				auto ret = __newFVector();
				*ret = self->GetClampedToSize2D(Min, Max);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetClampedToSize2D error, argc=%d", argc);
			return 0;
		}

		static int GetClampedToMaxSize(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto MaxSize = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFVector();
				*ret = self->GetClampedToMaxSize(MaxSize);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetClampedToMaxSize error, argc=%d", argc);
			return 0;
		}

		static int GetClampedToMaxSize2D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto MaxSize = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFVector();
				*ret = self->GetClampedToMaxSize2D(MaxSize);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetClampedToMaxSize2D error, argc=%d", argc);
			return 0;
		}

		static int AddBounded(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto Radius = LuaObject::checkValue<float>(L, 3);
				self->AddBounded(V2, Radius);
				return 0;
			}
			luaL_error(L, "call FVector::AddBounded error, argc=%d", argc);
			return 0;
		}

		static int Reciprocal(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = __newFVector();
				*ret = self->Reciprocal();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::Reciprocal error, argc=%d", argc);
			return 0;
		}

		static int IsUniform(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Tolerance = LuaObject::checkValue<float>(L, 2);
				auto ret = self->IsUniform(Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::IsUniform error, argc=%d", argc);
			return 0;
		}

		static int MirrorByVector(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto MirrorNormal = LuaObject::checkValue<FVector*>(L, 2);
				auto MirrorNormal2 = *MirrorNormal;
				auto ret = __newFVector();
				*ret = self->MirrorByVector(MirrorNormal2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::MirrorByVector error, argc=%d", argc);
			return 0;
		}

		static int RotateAngleAxis(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto AngleDeg = LuaObject::checkValue<float>(L, 2);
				auto AngleDeg2 = (const float)AngleDeg;
				auto Axis = LuaObject::checkValue<FVector*>(L, 3);
				auto Axis2 = *Axis;
				auto ret = __newFVector();
				*ret = self->RotateAngleAxis(AngleDeg2, Axis2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::RotateAngleAxis error, argc=%d", argc);
			return 0;
		}

		static int GetSafeNormal(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Tolerance = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFVector();
				*ret = self->GetSafeNormal(Tolerance);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetSafeNormal error, argc=%d", argc);
			return 0;
		}

		static int GetSafeNormal2D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Tolerance = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFVector();
				*ret = self->GetSafeNormal2D(Tolerance);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::GetSafeNormal2D error, argc=%d", argc);
			return 0;
		}

		static int CosineAngle2D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto B = LuaObject::checkValue<FVector*>(L, 2);
				auto B2 = *B;
				auto ret = self->CosineAngle2D(B2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::CosineAngle2D error, argc=%d", argc);
			return 0;
		}

		static int ProjectOnTo(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto A = LuaObject::checkValue<FVector*>(L, 2);
				auto A2 = *A;
				auto ret = __newFVector();
				*ret = self->ProjectOnTo(A2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::ProjectOnTo error, argc=%d", argc);
			return 0;
		}

		static int ProjectOnToNormal(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Normal = LuaObject::checkValue<FVector*>(L, 2);
				auto Normal2 = *Normal;
				auto ret = __newFVector();
				*ret = self->ProjectOnToNormal(Normal2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::ProjectOnToNormal error, argc=%d", argc);
			return 0;
		}

		static int ToOrientationRotator(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = __newFRotator();
				*ret = self->ToOrientationRotator();
				LuaObject::push<FRotator>(L, "FRotator", ret);
				return 1;
			}
			luaL_error(L, "call FVector::ToOrientationRotator error, argc=%d", argc);
			return 0;
		}

		static int Rotation(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = __newFRotator();
				*ret = self->Rotation();
				LuaObject::push<FRotator>(L, "FRotator", ret);
				return 1;
			}
			luaL_error(L, "call FVector::Rotation error, argc=%d", argc);
			return 0;
		}

		static int FindBestAxisVectors(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto Axis1 = LuaObject::checkValue<FVector*>(L, 2);
				auto Axis12 = *Axis1;
				auto Axis2 = LuaObject::checkValue<FVector*>(L, 3);
				auto Axis22 = *Axis2;
				self->FindBestAxisVectors(Axis12, Axis22);
				LuaObject::push<FVector>(L, "FVector", Axis1);
				LuaObject::push<FVector>(L, "FVector", Axis2);
				return 2;
			}
			luaL_error(L, "call FVector::FindBestAxisVectors error, argc=%d", argc);
			return 0;
		}

		static int UnwindEuler(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				self->UnwindEuler();
				return 0;
			}
			luaL_error(L, "call FVector::UnwindEuler error, argc=%d", argc);
			return 0;
		}

		static int ContainsNaN(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->ContainsNaN();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::ContainsNaN error, argc=%d", argc);
			return 0;
		}

		static int IsUnit(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto LengthSquaredTolerance = LuaObject::checkValue<float>(L, 2);
				auto ret = self->IsUnit(LengthSquaredTolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::IsUnit error, argc=%d", argc);
			return 0;
		}

		static int ToString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->ToString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::ToString error, argc=%d", argc);
			return 0;
		}

		static int ToCompactString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->ToCompactString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::ToCompactString error, argc=%d", argc);
			return 0;
		}

		static int InitFromString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto InSourceString = LuaObject::checkValue<FString>(L, 2);
				auto ret = self->InitFromString(InSourceString);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::InitFromString error, argc=%d", argc);
			return 0;
		}

		static int UnitCartesianToSpherical(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = __newFVector2D();
				*ret = self->UnitCartesianToSpherical();
				LuaObject::push<FVector2D>(L, "FVector2D", ret);
				return 1;
			}
			luaL_error(L, "call FVector::UnitCartesianToSpherical error, argc=%d", argc);
			return 0;
		}

		static int HeadingAngle(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector*>(L, 1);
				auto ret = self->HeadingAngle();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::HeadingAngle error, argc=%d", argc);
			return 0;
		}

		static int CrossProduct(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FVector*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FVector*>(L, 3);
				auto B2 = *B;
				auto ret = __newFVector();
				*ret = FVector::CrossProduct(A2, B2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::CrossProduct error, argc=%d", argc);
			return 0;
		}

		static int DotProduct(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FVector*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FVector*>(L, 3);
				auto B2 = *B;
				auto ret = FVector::DotProduct(A2, B2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::DotProduct error, argc=%d", argc);
			return 0;
		}

		static int CreateOrthonormalBasis(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto XAxis = LuaObject::checkValue<FVector*>(L, 2);
				auto XAxis2 = *XAxis;
				auto YAxis = LuaObject::checkValue<FVector*>(L, 3);
				auto YAxis2 = *YAxis;
				auto ZAxis = LuaObject::checkValue<FVector*>(L, 4);
				auto ZAxis2 = *ZAxis;
				FVector::CreateOrthonormalBasis(XAxis2, YAxis2, ZAxis2);
				LuaObject::push<FVector>(L, "FVector", XAxis);
				LuaObject::push<FVector>(L, "FVector", YAxis);
				LuaObject::push<FVector>(L, "FVector", ZAxis);
				return 3;
			}
			luaL_error(L, "call FVector::CreateOrthonormalBasis error, argc=%d", argc);
			return 0;
		}

		static int PointsAreSame(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto P = LuaObject::checkValue<FVector*>(L, 2);
				auto P2 = *P;
				auto Q = LuaObject::checkValue<FVector*>(L, 3);
				auto Q2 = *Q;
				auto ret = FVector::PointsAreSame(P2, Q2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::PointsAreSame error, argc=%d", argc);
			return 0;
		}

		static int PointsAreNear(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto Point1 = LuaObject::checkValue<FVector*>(L, 2);
				auto Point12 = *Point1;
				auto Point2 = LuaObject::checkValue<FVector*>(L, 3);
				auto Point22 = *Point2;
				auto Dist = LuaObject::checkValue<float>(L, 4);
				auto ret = FVector::PointsAreNear(Point12, Point22, Dist);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::PointsAreNear error, argc=%d", argc);
			return 0;
		}

		static int PointPlaneDist(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto Point = LuaObject::checkValue<FVector*>(L, 2);
				auto Point2 = *Point;
				auto PlaneBase = LuaObject::checkValue<FVector*>(L, 3);
				auto PlaneBase2 = *PlaneBase;
				auto PlaneNormal = LuaObject::checkValue<FVector*>(L, 4);
				auto PlaneNormal2 = *PlaneNormal;
				auto ret = FVector::PointPlaneDist(Point2, PlaneBase2, PlaneNormal2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::PointPlaneDist error, argc=%d", argc);
			return 0;
		}

		static int PointPlaneProject(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto Point = LuaObject::checkValue<FVector*>(L, 2);
				auto Point2 = *Point;
				auto PlaneBase = LuaObject::checkValue<FVector*>(L, 3);
				auto PlaneBase2 = *PlaneBase;
				auto PlaneNormal = LuaObject::checkValue<FVector*>(L, 4);
				auto PlaneNormal2 = *PlaneNormal;
				auto ret = __newFVector();
				*ret = FVector::PointPlaneProject(Point2, PlaneBase2, PlaneNormal2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			if (argc == 5) {
				auto Point = LuaObject::checkValue<FVector*>(L, 2);
				auto Point2 = *Point;
				auto A = LuaObject::checkValue<FVector*>(L, 3);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FVector*>(L, 4);
				auto B2 = *B;
				auto C = LuaObject::checkValue<FVector*>(L, 5);
				auto C2 = *C;
				auto ret = __newFVector();
				*ret = FVector::PointPlaneProject(Point2, A2, B2, C2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::PointPlaneProject error, argc=%d", argc);
			return 0;
		}

		static int VectorPlaneProject(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto V = LuaObject::checkValue<FVector*>(L, 2);
				auto V2 = *V;
				auto PlaneNormal = LuaObject::checkValue<FVector*>(L, 3);
				auto PlaneNormal2 = *PlaneNormal;
				auto ret = __newFVector();
				*ret = FVector::VectorPlaneProject(V2, PlaneNormal2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::VectorPlaneProject error, argc=%d", argc);
			return 0;
		}

		static int Dist(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto V1 = LuaObject::checkValue<FVector*>(L, 2);
				auto V12 = *V1;
				auto V2 = LuaObject::checkValue<FVector*>(L, 3);
				auto V22 = *V2;
				auto ret = FVector::Dist(V12, V22);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Dist error, argc=%d", argc);
			return 0;
		}

		static int Distance(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto V1 = LuaObject::checkValue<FVector*>(L, 2);
				auto V12 = *V1;
				auto V2 = LuaObject::checkValue<FVector*>(L, 3);
				auto V22 = *V2;
				auto ret = FVector::Distance(V12, V22);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Distance error, argc=%d", argc);
			return 0;
		}

		static int DistXY(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto V1 = LuaObject::checkValue<FVector*>(L, 2);
				auto V12 = *V1;
				auto V2 = LuaObject::checkValue<FVector*>(L, 3);
				auto V22 = *V2;
				auto ret = FVector::DistXY(V12, V22);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::DistXY error, argc=%d", argc);
			return 0;
		}

		static int Dist2D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto V1 = LuaObject::checkValue<FVector*>(L, 2);
				auto V12 = *V1;
				auto V2 = LuaObject::checkValue<FVector*>(L, 3);
				auto V22 = *V2;
				auto ret = FVector::Dist2D(V12, V22);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Dist2D error, argc=%d", argc);
			return 0;
		}

		static int DistSquared(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto V1 = LuaObject::checkValue<FVector*>(L, 2);
				auto V12 = *V1;
				auto V2 = LuaObject::checkValue<FVector*>(L, 3);
				auto V22 = *V2;
				auto ret = FVector::DistSquared(V12, V22);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::DistSquared error, argc=%d", argc);
			return 0;
		}

		static int DistSquaredXY(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto V1 = LuaObject::checkValue<FVector*>(L, 2);
				auto V12 = *V1;
				auto V2 = LuaObject::checkValue<FVector*>(L, 3);
				auto V22 = *V2;
				auto ret = FVector::DistSquaredXY(V12, V22);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::DistSquaredXY error, argc=%d", argc);
			return 0;
		}

		static int DistSquared2D(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto V1 = LuaObject::checkValue<FVector*>(L, 2);
				auto V12 = *V1;
				auto V2 = LuaObject::checkValue<FVector*>(L, 3);
				auto V22 = *V2;
				auto ret = FVector::DistSquared2D(V12, V22);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::DistSquared2D error, argc=%d", argc);
			return 0;
		}

		static int BoxPushOut(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto Normal = LuaObject::checkValue<FVector*>(L, 2);
				auto Normal2 = *Normal;
				auto Size = LuaObject::checkValue<FVector*>(L, 3);
				auto Size2 = *Size;
				auto ret = FVector::BoxPushOut(Normal2, Size2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::BoxPushOut error, argc=%d", argc);
			return 0;
		}

		static int Parallel(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto Normal1 = LuaObject::checkValue<FVector*>(L, 2);
				auto Normal12 = *Normal1;
				auto Normal2 = LuaObject::checkValue<FVector*>(L, 3);
				auto Normal22 = *Normal2;
				auto ParallelCosineThreshold = LuaObject::checkValue<float>(L, 4);
				auto ret = FVector::Parallel(Normal12, Normal22, ParallelCosineThreshold);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Parallel error, argc=%d", argc);
			return 0;
		}

		static int Coincident(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto Normal1 = LuaObject::checkValue<FVector*>(L, 2);
				auto Normal12 = *Normal1;
				auto Normal2 = LuaObject::checkValue<FVector*>(L, 3);
				auto Normal22 = *Normal2;
				auto ParallelCosineThreshold = LuaObject::checkValue<float>(L, 4);
				auto ret = FVector::Coincident(Normal12, Normal22, ParallelCosineThreshold);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Coincident error, argc=%d", argc);
			return 0;
		}

		static int Orthogonal(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto Normal1 = LuaObject::checkValue<FVector*>(L, 2);
				auto Normal12 = *Normal1;
				auto Normal2 = LuaObject::checkValue<FVector*>(L, 3);
				auto Normal22 = *Normal2;
				auto OrthogonalCosineThreshold = LuaObject::checkValue<float>(L, 4);
				auto ret = FVector::Orthogonal(Normal12, Normal22, OrthogonalCosineThreshold);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Orthogonal error, argc=%d", argc);
			return 0;
		}

		static int Coplanar(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 6) {
				auto Base1 = LuaObject::checkValue<FVector*>(L, 2);
				auto Base12 = *Base1;
				auto Normal1 = LuaObject::checkValue<FVector*>(L, 3);
				auto Normal12 = *Normal1;
				auto Base2 = LuaObject::checkValue<FVector*>(L, 4);
				auto Base22 = *Base2;
				auto Normal2 = LuaObject::checkValue<FVector*>(L, 5);
				auto Normal22 = *Normal2;
				auto ParallelCosineThreshold = LuaObject::checkValue<float>(L, 6);
				auto ret = FVector::Coplanar(Base12, Normal12, Base22, Normal22, ParallelCosineThreshold);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Coplanar error, argc=%d", argc);
			return 0;
		}

		static int Triple(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto X = LuaObject::checkValue<FVector*>(L, 2);
				auto X2 = *X;
				auto Y = LuaObject::checkValue<FVector*>(L, 3);
				auto Y2 = *Y;
				auto Z = LuaObject::checkValue<FVector*>(L, 4);
				auto Z2 = *Z;
				auto ret = FVector::Triple(X2, Y2, Z2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector::Triple error, argc=%d", argc);
			return 0;
		}

		static int RadiansToDegrees(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto RadVector = LuaObject::checkValue<FVector*>(L, 2);
				auto RadVector2 = *RadVector;
				auto ret = __newFVector();
				*ret = FVector::RadiansToDegrees(RadVector2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::RadiansToDegrees error, argc=%d", argc);
			return 0;
		}

		static int DegreesToRadians(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto DegVector = LuaObject::checkValue<FVector*>(L, 2);
				auto DegVector2 = *DegVector;
				auto ret = __newFVector();
				*ret = FVector::DegreesToRadians(DegVector2);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector::DegreesToRadians error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FVector");
			LuaObject::addField(L, "X", get_X, set_X, true);
			LuaObject::addField(L, "Y", get_Y, set_Y, true);
			LuaObject::addField(L, "Z", get_Z, set_Z, true);
			LuaObject::addField(L, "ZeroVector", get_ZeroVector, nullptr, false);
			LuaObject::addField(L, "OneVector", get_OneVector, nullptr, false);
			LuaObject::addField(L, "UpVector", get_UpVector, nullptr, false);
			LuaObject::addField(L, "ForwardVector", get_ForwardVector, nullptr, false);
			LuaObject::addField(L, "RightVector", get_RightVector, nullptr, false);
			LuaObject::addMethod(L, "DiagnosticCheckNaN", DiagnosticCheckNaN, true);
			LuaObject::addMethod(L, "Equals", Equals, true);
			LuaObject::addMethod(L, "AllComponentsEqual", AllComponentsEqual, true);
			LuaObject::addMethod(L, "Component", Component, true);
			LuaObject::addMethod(L, "GetComponentForAxis", GetComponentForAxis, true);
			LuaObject::addMethod(L, "SetComponentForAxis", SetComponentForAxis, true);
			LuaObject::addMethod(L, "Set", Set, true);
			LuaObject::addMethod(L, "GetMax", GetMax, true);
			LuaObject::addMethod(L, "GetAbsMax", GetAbsMax, true);
			LuaObject::addMethod(L, "GetMin", GetMin, true);
			LuaObject::addMethod(L, "GetAbsMin", GetAbsMin, true);
			LuaObject::addMethod(L, "ComponentMin", ComponentMin, true);
			LuaObject::addMethod(L, "ComponentMax", ComponentMax, true);
			LuaObject::addMethod(L, "GetAbs", GetAbs, true);
			LuaObject::addMethod(L, "Size", Size, true);
			LuaObject::addMethod(L, "SizeSquared", SizeSquared, true);
			LuaObject::addMethod(L, "Size2D", Size2D, true);
			LuaObject::addMethod(L, "SizeSquared2D", SizeSquared2D, true);
			LuaObject::addMethod(L, "IsNearlyZero", IsNearlyZero, true);
			LuaObject::addMethod(L, "IsZero", IsZero, true);
			LuaObject::addMethod(L, "Normalize", Normalize, true);
			LuaObject::addMethod(L, "IsNormalized", IsNormalized, true);
			LuaObject::addMethod(L, "ToDirectionAndLength", ToDirectionAndLength, true);
			LuaObject::addMethod(L, "GetSignVector", GetSignVector, true);
			LuaObject::addMethod(L, "Projection", Projection, true);
			LuaObject::addMethod(L, "GetUnsafeNormal", GetUnsafeNormal, true);
			LuaObject::addMethod(L, "GridSnap", GridSnap, true);
			LuaObject::addMethod(L, "BoundToCube", BoundToCube, true);
			LuaObject::addMethod(L, "GetClampedToSize", GetClampedToSize, true);
			LuaObject::addMethod(L, "GetClampedToSize2D", GetClampedToSize2D, true);
			LuaObject::addMethod(L, "GetClampedToMaxSize", GetClampedToMaxSize, true);
			LuaObject::addMethod(L, "GetClampedToMaxSize2D", GetClampedToMaxSize2D, true);
			LuaObject::addMethod(L, "AddBounded", AddBounded, true);
			LuaObject::addMethod(L, "Reciprocal", Reciprocal, true);
			LuaObject::addMethod(L, "IsUniform", IsUniform, true);
			LuaObject::addMethod(L, "MirrorByVector", MirrorByVector, true);
			LuaObject::addMethod(L, "RotateAngleAxis", RotateAngleAxis, true);
			LuaObject::addMethod(L, "GetSafeNormal", GetSafeNormal, true);
			LuaObject::addMethod(L, "GetSafeNormal2D", GetSafeNormal2D, true);
			LuaObject::addMethod(L, "CosineAngle2D", CosineAngle2D, true);
			LuaObject::addMethod(L, "ProjectOnTo", ProjectOnTo, true);
			LuaObject::addMethod(L, "ProjectOnToNormal", ProjectOnToNormal, true);
			LuaObject::addMethod(L, "ToOrientationRotator", ToOrientationRotator, true);
			LuaObject::addMethod(L, "Rotation", Rotation, true);
			LuaObject::addMethod(L, "FindBestAxisVectors", FindBestAxisVectors, true);
			LuaObject::addMethod(L, "UnwindEuler", UnwindEuler, true);
			LuaObject::addMethod(L, "ContainsNaN", ContainsNaN, true);
			LuaObject::addMethod(L, "IsUnit", IsUnit, true);
			LuaObject::addMethod(L, "ToString", ToString, true);
			LuaObject::addMethod(L, "ToCompactString", ToCompactString, true);
			LuaObject::addMethod(L, "InitFromString", InitFromString, true);
			LuaObject::addMethod(L, "UnitCartesianToSpherical", UnitCartesianToSpherical, true);
			LuaObject::addMethod(L, "HeadingAngle", HeadingAngle, true);
			LuaObject::addMethod(L, "CrossProduct", CrossProduct, false);
			LuaObject::addMethod(L, "DotProduct", DotProduct, false);
			LuaObject::addMethod(L, "CreateOrthonormalBasis", CreateOrthonormalBasis, false);
			LuaObject::addMethod(L, "PointsAreSame", PointsAreSame, false);
			LuaObject::addMethod(L, "PointsAreNear", PointsAreNear, false);
			LuaObject::addMethod(L, "PointPlaneDist", PointPlaneDist, false);
			LuaObject::addMethod(L, "PointPlaneProject", PointPlaneProject, false);
			LuaObject::addMethod(L, "VectorPlaneProject", VectorPlaneProject, false);
			LuaObject::addMethod(L, "Dist", Dist, false);
			LuaObject::addMethod(L, "Distance", Distance, false);
			LuaObject::addMethod(L, "DistXY", DistXY, false);
			LuaObject::addMethod(L, "Dist2D", Dist2D, false);
			LuaObject::addMethod(L, "DistSquared", DistSquared, false);
			LuaObject::addMethod(L, "DistSquaredXY", DistSquaredXY, false);
			LuaObject::addMethod(L, "DistSquared2D", DistSquared2D, false);
			LuaObject::addMethod(L, "BoxPushOut", BoxPushOut, false);
			LuaObject::addMethod(L, "Parallel", Parallel, false);
			LuaObject::addMethod(L, "Coincident", Coincident, false);
			LuaObject::addMethod(L, "Orthogonal", Orthogonal, false);
			LuaObject::addMethod(L, "Coplanar", Coplanar, false);
			LuaObject::addMethod(L, "Triple", Triple, false);
			LuaObject::addMethod(L, "RadiansToDegrees", RadiansToDegrees, false);
			LuaObject::addMethod(L, "DegreesToRadians", DegreesToRadians, false);
			LuaObject::finishType(L, "FVector", __ctor, __gc);
		}

	};

	struct FVector2DWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FVector2D();
				LuaObject::push<FVector2D>(L, "FVector2D", self);
				return 1;
			}
			if (argc == 2) {
				auto _a0 = LuaObject::checkValue<int>(L, 2);
				auto _a02 = (EForceInit)_a0;
				auto self = new FVector2D(_a02);
				LuaObject::push<FVector2D>(L, "FVector2D", self);
				return 1;
			}
			if (argc == 3) {
				auto InX = LuaObject::checkValue<float>(L, 2);
				auto InY = LuaObject::checkValue<float>(L, 3);
				auto self = new FVector2D(InX, InY);
				LuaObject::push<FVector2D>(L, "FVector2D", self);
				return 1;
			}
			luaL_error(L, "call FVector2D() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FVector2D*>(L, 1);
			delete self;
			return 0;
		}

		static int get_X(lua_State* L) {
			auto self = LuaObject::checkValue<FVector2D*>(L, 1);
			LuaObject::push(L, self->X);
			return 1;
		}

		static int set_X(lua_State* L) {
			auto self = LuaObject::checkValue<FVector2D*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->X = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_Y(lua_State* L) {
			auto self = LuaObject::checkValue<FVector2D*>(L, 1);
			LuaObject::push(L, self->Y);
			return 1;
		}

		static int set_Y(lua_State* L) {
			auto self = LuaObject::checkValue<FVector2D*>(L, 1);
			auto a1 = LuaObject::checkValue<float>(L, 2);
			self->Y = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_ZeroVector(lua_State* L) {
			LuaObject::push<FVector2D>(L, "FVector2D", &FVector2D::ZeroVector);
			return 1;
		}

		static int get_UnitVector(lua_State* L) {
			LuaObject::push<FVector2D>(L, "FVector2D", &FVector2D::UnitVector);
			return 1;
		}

		static int Component(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto Index = LuaObject::checkValue<int>(L, 2);
				auto ret = self->Component(Index);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::Component error, argc=%d", argc);
			return 0;
		}

		static int Equals(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto V = LuaObject::checkValue<FVector2D*>(L, 2);
				auto V2 = *V;
				auto Tolerance = LuaObject::checkValue<float>(L, 3);
				auto ret = self->Equals(V2, Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::Equals error, argc=%d", argc);
			return 0;
		}

		static int Set(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto InX = LuaObject::checkValue<float>(L, 2);
				auto InY = LuaObject::checkValue<float>(L, 3);
				self->Set(InX, InY);
				return 0;
			}
			luaL_error(L, "call FVector2D::Set error, argc=%d", argc);
			return 0;
		}

		static int GetMax(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = self->GetMax();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::GetMax error, argc=%d", argc);
			return 0;
		}

		static int GetAbsMax(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = self->GetAbsMax();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::GetAbsMax error, argc=%d", argc);
			return 0;
		}

		static int GetMin(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = self->GetMin();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::GetMin error, argc=%d", argc);
			return 0;
		}

		static int Size(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = self->Size();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::Size error, argc=%d", argc);
			return 0;
		}

		static int SizeSquared(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = self->SizeSquared();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::SizeSquared error, argc=%d", argc);
			return 0;
		}

		static int GetRotated(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto AngleDeg = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFVector2D();
				*ret = self->GetRotated(AngleDeg);
				LuaObject::push<FVector2D>(L, "FVector2D", ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::GetRotated error, argc=%d", argc);
			return 0;
		}

		static int GetSafeNormal(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto Tolerance = LuaObject::checkValue<float>(L, 2);
				auto ret = __newFVector2D();
				*ret = self->GetSafeNormal(Tolerance);
				LuaObject::push<FVector2D>(L, "FVector2D", ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::GetSafeNormal error, argc=%d", argc);
			return 0;
		}

		static int Normalize(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto Tolerance = LuaObject::checkValue<float>(L, 2);
				self->Normalize(Tolerance);
				return 0;
			}
			luaL_error(L, "call FVector2D::Normalize error, argc=%d", argc);
			return 0;
		}

		static int IsNearlyZero(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto Tolerance = LuaObject::checkValue<float>(L, 2);
				auto ret = self->IsNearlyZero(Tolerance);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::IsNearlyZero error, argc=%d", argc);
			return 0;
		}

		static int ToDirectionAndLength(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto OutDir = LuaObject::checkValue<FVector2D*>(L, 2);
				auto OutDir2 = *OutDir;
				auto OutLength = LuaObject::checkValue<float>(L, 3);
				self->ToDirectionAndLength(OutDir2, OutLength);
				LuaObject::push<FVector2D>(L, "FVector2D", OutDir);
				LuaObject::push(L, OutLength);
				return 2;
			}
			luaL_error(L, "call FVector2D::ToDirectionAndLength error, argc=%d", argc);
			return 0;
		}

		static int IsZero(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = self->IsZero();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::IsZero error, argc=%d", argc);
			return 0;
		}

		static int RoundToVector(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = __newFVector2D();
				*ret = self->RoundToVector();
				LuaObject::push<FVector2D>(L, "FVector2D", ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::RoundToVector error, argc=%d", argc);
			return 0;
		}

		static int ClampAxes(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto MinAxisVal = LuaObject::checkValue<float>(L, 2);
				auto MaxAxisVal = LuaObject::checkValue<float>(L, 3);
				auto ret = __newFVector2D();
				*ret = self->ClampAxes(MinAxisVal, MaxAxisVal);
				LuaObject::push<FVector2D>(L, "FVector2D", ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::ClampAxes error, argc=%d", argc);
			return 0;
		}

		static int GetSignVector(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = __newFVector2D();
				*ret = self->GetSignVector();
				LuaObject::push<FVector2D>(L, "FVector2D", ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::GetSignVector error, argc=%d", argc);
			return 0;
		}

		static int GetAbs(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = __newFVector2D();
				*ret = self->GetAbs();
				LuaObject::push<FVector2D>(L, "FVector2D", ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::GetAbs error, argc=%d", argc);
			return 0;
		}

		static int ToString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = self->ToString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::ToString error, argc=%d", argc);
			return 0;
		}

		static int InitFromString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto InSourceString = LuaObject::checkValue<FString>(L, 2);
				auto ret = self->InitFromString(InSourceString);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::InitFromString error, argc=%d", argc);
			return 0;
		}

		static int DiagnosticCheckNaN(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				self->DiagnosticCheckNaN();
				return 0;
			}
			luaL_error(L, "call FVector2D::DiagnosticCheckNaN error, argc=%d", argc);
			return 0;
		}

		static int ContainsNaN(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = self->ContainsNaN();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::ContainsNaN error, argc=%d", argc);
			return 0;
		}

		static int SphericalToUnitCartesian(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FVector2D*>(L, 1);
				auto ret = __newFVector();
				*ret = self->SphericalToUnitCartesian();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::SphericalToUnitCartesian error, argc=%d", argc);
			return 0;
		}

		static int DotProduct(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FVector2D*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FVector2D*>(L, 3);
				auto B2 = *B;
				auto ret = FVector2D::DotProduct(A2, B2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::DotProduct error, argc=%d", argc);
			return 0;
		}

		static int DistSquared(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto V1 = LuaObject::checkValue<FVector2D*>(L, 2);
				auto V12 = *V1;
				auto V2 = LuaObject::checkValue<FVector2D*>(L, 3);
				auto V22 = *V2;
				auto ret = FVector2D::DistSquared(V12, V22);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::DistSquared error, argc=%d", argc);
			return 0;
		}

		static int Distance(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto V1 = LuaObject::checkValue<FVector2D*>(L, 2);
				auto V12 = *V1;
				auto V2 = LuaObject::checkValue<FVector2D*>(L, 3);
				auto V22 = *V2;
				auto ret = FVector2D::Distance(V12, V22);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::Distance error, argc=%d", argc);
			return 0;
		}

		static int CrossProduct(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FVector2D*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FVector2D*>(L, 3);
				auto B2 = *B;
				auto ret = FVector2D::CrossProduct(A2, B2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FVector2D::CrossProduct error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FVector2D");
			LuaObject::addField(L, "X", get_X, set_X, true);
			LuaObject::addField(L, "Y", get_Y, set_Y, true);
			LuaObject::addField(L, "ZeroVector", get_ZeroVector, nullptr, false);
			LuaObject::addField(L, "UnitVector", get_UnitVector, nullptr, false);
			LuaObject::addMethod(L, "Component", Component, true);
			LuaObject::addMethod(L, "Equals", Equals, true);
			LuaObject::addMethod(L, "Set", Set, true);
			LuaObject::addMethod(L, "GetMax", GetMax, true);
			LuaObject::addMethod(L, "GetAbsMax", GetAbsMax, true);
			LuaObject::addMethod(L, "GetMin", GetMin, true);
			LuaObject::addMethod(L, "Size", Size, true);
			LuaObject::addMethod(L, "SizeSquared", SizeSquared, true);
			LuaObject::addMethod(L, "GetRotated", GetRotated, true);
			LuaObject::addMethod(L, "GetSafeNormal", GetSafeNormal, true);
			LuaObject::addMethod(L, "Normalize", Normalize, true);
			LuaObject::addMethod(L, "IsNearlyZero", IsNearlyZero, true);
			LuaObject::addMethod(L, "ToDirectionAndLength", ToDirectionAndLength, true);
			LuaObject::addMethod(L, "IsZero", IsZero, true);
			LuaObject::addMethod(L, "RoundToVector", RoundToVector, true);
			LuaObject::addMethod(L, "ClampAxes", ClampAxes, true);
			LuaObject::addMethod(L, "GetSignVector", GetSignVector, true);
			LuaObject::addMethod(L, "GetAbs", GetAbs, true);
			LuaObject::addMethod(L, "ToString", ToString, true);
			LuaObject::addMethod(L, "InitFromString", InitFromString, true);
			LuaObject::addMethod(L, "DiagnosticCheckNaN", DiagnosticCheckNaN, true);
			LuaObject::addMethod(L, "ContainsNaN", ContainsNaN, true);
			LuaObject::addMethod(L, "SphericalToUnitCartesian", SphericalToUnitCartesian, true);
			LuaObject::addMethod(L, "DotProduct", DotProduct, false);
			LuaObject::addMethod(L, "DistSquared", DistSquared, false);
			LuaObject::addMethod(L, "Distance", Distance, false);
			LuaObject::addMethod(L, "CrossProduct", CrossProduct, false);
			LuaObject::finishType(L, "FVector2D", __ctor, __gc);
		}

	};

	struct FRandomStreamWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FRandomStream();
				LuaObject::push<FRandomStream>(L, "FRandomStream", self);
				return 1;
			}
			if (argc == 2) {
				auto InSeed = LuaObject::checkValue<int>(L, 2);
				auto self = new FRandomStream(InSeed);
				LuaObject::push<FRandomStream>(L, "FRandomStream", self);
				return 1;
			}
			luaL_error(L, "call FRandomStream() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
			delete self;
			return 0;
		}

		static int Initialize(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto InSeed = LuaObject::checkValue<int>(L, 2);
				self->Initialize(InSeed);
				return 0;
			}
			luaL_error(L, "call FRandomStream::Initialize error, argc=%d", argc);
			return 0;
		}

		static int Reset(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				self->Reset();
				return 0;
			}
			luaL_error(L, "call FRandomStream::Reset error, argc=%d", argc);
			return 0;
		}

		static int GetInitialSeed(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto ret = self->GetInitialSeed();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRandomStream::GetInitialSeed error, argc=%d", argc);
			return 0;
		}

		static int GenerateNewSeed(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				self->GenerateNewSeed();
				return 0;
			}
			luaL_error(L, "call FRandomStream::GenerateNewSeed error, argc=%d", argc);
			return 0;
		}

		static int GetFraction(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto ret = self->GetFraction();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRandomStream::GetFraction error, argc=%d", argc);
			return 0;
		}

		static int GetUnsignedInt(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto ret = self->GetUnsignedInt();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRandomStream::GetUnsignedInt error, argc=%d", argc);
			return 0;
		}

		static int GetUnitVector(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto ret = __newFVector();
				*ret = self->GetUnitVector();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FRandomStream::GetUnitVector error, argc=%d", argc);
			return 0;
		}

		static int GetCurrentSeed(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto ret = self->GetCurrentSeed();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRandomStream::GetCurrentSeed error, argc=%d", argc);
			return 0;
		}

		static int FRand(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto ret = self->FRand();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRandomStream::FRand error, argc=%d", argc);
			return 0;
		}

		static int RandHelper(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto A = LuaObject::checkValue<int>(L, 2);
				auto ret = self->RandHelper(A);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRandomStream::RandHelper error, argc=%d", argc);
			return 0;
		}

		static int RandRange(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto Min = LuaObject::checkValue<int>(L, 2);
				auto Max = LuaObject::checkValue<int>(L, 3);
				auto ret = self->RandRange(Min, Max);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRandomStream::RandRange error, argc=%d", argc);
			return 0;
		}

		static int FRandRange(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto InMin = LuaObject::checkValue<float>(L, 2);
				auto InMax = LuaObject::checkValue<float>(L, 3);
				auto ret = self->FRandRange(InMin, InMax);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FRandomStream::FRandRange error, argc=%d", argc);
			return 0;
		}

		static int VRand(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto ret = __newFVector();
				*ret = self->VRand();
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FRandomStream::VRand error, argc=%d", argc);
			return 0;
		}

		static int VRandCone(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto Dir = LuaObject::checkValue<FVector*>(L, 2);
				auto Dir2 = *Dir;
				auto ConeHalfAngleRad = LuaObject::checkValue<float>(L, 3);
				auto ret = __newFVector();
				*ret = self->VRandCone(Dir2, ConeHalfAngleRad);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			if (argc == 4) {
				auto self = LuaObject::checkValue<FRandomStream*>(L, 1);
				auto Dir = LuaObject::checkValue<FVector*>(L, 2);
				auto Dir2 = *Dir;
				auto HorizontalConeHalfAngleRad = LuaObject::checkValue<float>(L, 3);
				auto VerticalConeHalfAngleRad = LuaObject::checkValue<float>(L, 4);
				auto ret = __newFVector();
				*ret = self->VRandCone(Dir2, HorizontalConeHalfAngleRad, VerticalConeHalfAngleRad);
				LuaObject::push<FVector>(L, "FVector", ret);
				return 1;
			}
			luaL_error(L, "call FRandomStream::VRandCone error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FRandomStream");
			LuaObject::addMethod(L, "Initialize", Initialize, true);
			LuaObject::addMethod(L, "Reset", Reset, true);
			LuaObject::addMethod(L, "GetInitialSeed", GetInitialSeed, true);
			LuaObject::addMethod(L, "GenerateNewSeed", GenerateNewSeed, true);
			LuaObject::addMethod(L, "GetFraction", GetFraction, true);
			LuaObject::addMethod(L, "GetUnsignedInt", GetUnsignedInt, true);
			LuaObject::addMethod(L, "GetUnitVector", GetUnitVector, true);
			LuaObject::addMethod(L, "GetCurrentSeed", GetCurrentSeed, true);
			LuaObject::addMethod(L, "FRand", FRand, true);
			LuaObject::addMethod(L, "RandHelper", RandHelper, true);
			LuaObject::addMethod(L, "RandRange", RandRange, true);
			LuaObject::addMethod(L, "FRandRange", FRandRange, true);
			LuaObject::addMethod(L, "VRand", VRand, true);
			LuaObject::addMethod(L, "VRandCone", VRandCone, true);
			LuaObject::finishType(L, "FRandomStream", __ctor, __gc);
		}

	};

	struct FGuidWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FGuid();
				LuaObject::push<FGuid>(L, "FGuid", self);
				return 1;
			}
			if (argc == 5) {
				auto InA = LuaObject::checkValue<int>(L, 2);
				auto InA2 = (unsigned int)InA;
				auto InB = LuaObject::checkValue<int>(L, 3);
				auto InB2 = (unsigned int)InB;
				auto InC = LuaObject::checkValue<int>(L, 4);
				auto InC2 = (unsigned int)InC;
				auto InD = LuaObject::checkValue<int>(L, 5);
				auto InD2 = (unsigned int)InD;
				auto self = new FGuid(InA2, InB2, InC2, InD2);
				LuaObject::push<FGuid>(L, "FGuid", self);
				return 1;
			}
			luaL_error(L, "call FGuid() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FGuid*>(L, 1);
			delete self;
			return 0;
		}

		static int get_A(lua_State* L) {
			auto self = LuaObject::checkValue<FGuid*>(L, 1);
			LuaObject::push(L, self->A);
			return 1;
		}

		static int set_A(lua_State* L) {
			auto self = LuaObject::checkValue<FGuid*>(L, 1);
			auto a1 = LuaObject::checkValue<uint32>(L, 2);
			self->A = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_B(lua_State* L) {
			auto self = LuaObject::checkValue<FGuid*>(L, 1);
			LuaObject::push(L, self->B);
			return 1;
		}

		static int set_B(lua_State* L) {
			auto self = LuaObject::checkValue<FGuid*>(L, 1);
			auto a1 = LuaObject::checkValue<uint32>(L, 2);
			self->B = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_C(lua_State* L) {
			auto self = LuaObject::checkValue<FGuid*>(L, 1);
			LuaObject::push(L, self->C);
			return 1;
		}

		static int set_C(lua_State* L) {
			auto self = LuaObject::checkValue<FGuid*>(L, 1);
			auto a1 = LuaObject::checkValue<uint32>(L, 2);
			self->C = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int get_D(lua_State* L) {
			auto self = LuaObject::checkValue<FGuid*>(L, 1);
			LuaObject::push(L, self->D);
			return 1;
		}

		static int set_D(lua_State* L) {
			auto self = LuaObject::checkValue<FGuid*>(L, 1);
			auto a1 = LuaObject::checkValue<uint32>(L, 2);
			self->D = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int Invalidate(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FGuid*>(L, 1);
				self->Invalidate();
				return 0;
			}
			luaL_error(L, "call FGuid::Invalidate error, argc=%d", argc);
			return 0;
		}

		static int IsValid(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FGuid*>(L, 1);
				auto ret = self->IsValid();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FGuid::IsValid error, argc=%d", argc);
			return 0;
		}

		static int ToString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FGuid*>(L, 1);
				auto ret = self->ToString();
				LuaObject::push(L, ret);
				return 1;
			}
			if (argc == 2) {
				auto self = LuaObject::checkValue<FGuid*>(L, 1);
				auto Format = LuaObject::checkValue<int>(L, 2);
				auto Format2 = (EGuidFormats)Format;
				auto ret = self->ToString(Format2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FGuid::ToString error, argc=%d", argc);
			return 0;
		}

		static int NewGuid(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto ret = __newFGuid();
				*ret = FGuid::NewGuid();
				LuaObject::push<FGuid>(L, "FGuid", ret);
				return 1;
			}
			luaL_error(L, "call FGuid::NewGuid error, argc=%d", argc);
			return 0;
		}

		static int Parse(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto GuidString = LuaObject::checkValue<FString>(L, 2);
				auto OutGuid = LuaObject::checkValue<FGuid*>(L, 3);
				auto OutGuid2 = *OutGuid;
				auto ret = FGuid::Parse(GuidString, OutGuid2);
				LuaObject::push(L, ret);
				LuaObject::push<FGuid>(L, "FGuid", OutGuid);
				return 2;
			}
			luaL_error(L, "call FGuid::Parse error, argc=%d", argc);
			return 0;
		}

		static int ParseExact(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 4) {
				auto GuidString = LuaObject::checkValue<FString>(L, 2);
				auto Format = LuaObject::checkValue<int>(L, 3);
				auto Format2 = (EGuidFormats)Format;
				auto OutGuid = LuaObject::checkValue<FGuid*>(L, 4);
				auto OutGuid2 = *OutGuid;
				auto ret = FGuid::ParseExact(GuidString, Format2, OutGuid2);
				LuaObject::push(L, ret);
				LuaObject::push<FGuid>(L, "FGuid", OutGuid);
				return 2;
			}
			luaL_error(L, "call FGuid::ParseExact error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FGuid");
			LuaObject::addField(L, "A", get_A, set_A, true);
			LuaObject::addField(L, "B", get_B, set_B, true);
			LuaObject::addField(L, "C", get_C, set_C, true);
			LuaObject::addField(L, "D", get_D, set_D, true);
			LuaObject::addMethod(L, "Invalidate", Invalidate, true);
			LuaObject::addMethod(L, "IsValid", IsValid, true);
			LuaObject::addMethod(L, "ToString", ToString, true);
			LuaObject::addMethod(L, "NewGuid", NewGuid, false);
			LuaObject::addMethod(L, "Parse", Parse, false);
			LuaObject::addMethod(L, "ParseExact", ParseExact, false);
			LuaObject::finishType(L, "FGuid", __ctor, __gc);
		}

	};

	struct FBox2DWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FBox2D();
				LuaObject::push<FBox2D>(L, "FBox2D", self);
				return 1;
			}
			if (argc == 2) {
				auto _a0 = LuaObject::checkValue<int>(L, 2);
				auto _a02 = (EForceInit)_a0;
				auto self = new FBox2D(_a02);
				LuaObject::push<FBox2D>(L, "FBox2D", self);
				return 1;
			}
			if (argc == 3) {
				auto InMin = LuaObject::checkValue<FVector2D*>(L, 2);
				auto InMin2 = *InMin;
				auto InMax = LuaObject::checkValue<FVector2D*>(L, 3);
				auto InMax2 = *InMax;
				auto self = new FBox2D(InMin2, InMax2);
				LuaObject::push<FBox2D>(L, "FBox2D", self);
				return 1;
			}
			luaL_error(L, "call FBox2D() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FBox2D*>(L, 1);
			delete self;
			return 0;
		}

		static int get_Min(lua_State* L) {
			auto self = LuaObject::checkValue<FBox2D*>(L, 1);
			LuaObject::push<FVector2D>(L, "FVector2D", &self->Min);
			return 1;
		}

		static int set_Min(lua_State* L) {
			auto self = LuaObject::checkValue<FBox2D*>(L, 1);
			auto a1 = LuaObject::checkValue<FVector2D*>(L, 2);
			self->Min = *a1;
			LuaObject::push<FVector2D>(L, "FVector2D", a1);
			return 1;
		}

		static int get_Max(lua_State* L) {
			auto self = LuaObject::checkValue<FBox2D*>(L, 1);
			LuaObject::push<FVector2D>(L, "FVector2D", &self->Max);
			return 1;
		}

		static int set_Max(lua_State* L) {
			auto self = LuaObject::checkValue<FBox2D*>(L, 1);
			auto a1 = LuaObject::checkValue<FVector2D*>(L, 2);
			self->Max = *a1;
			LuaObject::push<FVector2D>(L, "FVector2D", a1);
			return 1;
		}

		static int get_bIsValid(lua_State* L) {
			auto self = LuaObject::checkValue<FBox2D*>(L, 1);
			LuaObject::push(L, self->bIsValid);
			return 1;
		}

		static int set_bIsValid(lua_State* L) {
			auto self = LuaObject::checkValue<FBox2D*>(L, 1);
			auto a1 = LuaObject::checkValue<bool>(L, 2);
			self->bIsValid = a1;
			LuaObject::push(L, a1);
			return 1;
		}

		static int ComputeSquaredDistanceToPoint(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto Point = LuaObject::checkValue<FVector2D*>(L, 2);
				auto Point2 = *Point;
				auto ret = self->ComputeSquaredDistanceToPoint(Point2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FBox2D::ComputeSquaredDistanceToPoint error, argc=%d", argc);
			return 0;
		}

		static int ExpandBy(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto W = LuaObject::checkValue<float>(L, 2);
				auto W2 = (const float)W;
				auto ret = __newFBox2D();
				*ret = self->ExpandBy(W2);
				LuaObject::push<FBox2D>(L, "FBox2D", ret);
				return 1;
			}
			luaL_error(L, "call FBox2D::ExpandBy error, argc=%d", argc);
			return 0;
		}

		static int GetArea(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto ret = self->GetArea();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FBox2D::GetArea error, argc=%d", argc);
			return 0;
		}

		static int GetCenter(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto ret = __newFVector2D();
				*ret = self->GetCenter();
				LuaObject::push<FVector2D>(L, "FVector2D", ret);
				return 1;
			}
			luaL_error(L, "call FBox2D::GetCenter error, argc=%d", argc);
			return 0;
		}

		static int GetCenterAndExtents(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto center = LuaObject::checkValue<FVector2D*>(L, 2);
				auto center2 = *center;
				auto Extents = LuaObject::checkValue<FVector2D*>(L, 3);
				auto Extents2 = *Extents;
				self->GetCenterAndExtents(center2, Extents2);
				LuaObject::push<FVector2D>(L, "FVector2D", center);
				LuaObject::push<FVector2D>(L, "FVector2D", Extents);
				return 2;
			}
			luaL_error(L, "call FBox2D::GetCenterAndExtents error, argc=%d", argc);
			return 0;
		}

		static int GetClosestPointTo(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto Point = LuaObject::checkValue<FVector2D*>(L, 2);
				auto Point2 = *Point;
				auto ret = __newFVector2D();
				*ret = self->GetClosestPointTo(Point2);
				LuaObject::push<FVector2D>(L, "FVector2D", ret);
				return 1;
			}
			luaL_error(L, "call FBox2D::GetClosestPointTo error, argc=%d", argc);
			return 0;
		}

		static int GetExtent(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto ret = __newFVector2D();
				*ret = self->GetExtent();
				LuaObject::push<FVector2D>(L, "FVector2D", ret);
				return 1;
			}
			luaL_error(L, "call FBox2D::GetExtent error, argc=%d", argc);
			return 0;
		}

		static int GetSize(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto ret = __newFVector2D();
				*ret = self->GetSize();
				LuaObject::push<FVector2D>(L, "FVector2D", ret);
				return 1;
			}
			luaL_error(L, "call FBox2D::GetSize error, argc=%d", argc);
			return 0;
		}

		static int Init(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				self->Init();
				return 0;
			}
			luaL_error(L, "call FBox2D::Init error, argc=%d", argc);
			return 0;
		}

		static int Intersect(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto other = LuaObject::checkValue<FBox2D*>(L, 2);
				auto other2 = *other;
				auto ret = self->Intersect(other2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FBox2D::Intersect error, argc=%d", argc);
			return 0;
		}

		static int IsInside(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto TestPoint = LuaObject::checkValue<FVector2D*>(L, 2);
				auto TestPoint2 = *TestPoint;
				auto ret = self->IsInside(TestPoint2);
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FBox2D::IsInside error, argc=%d", argc);
			return 0;
		}

		static int ShiftBy(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto Offset = LuaObject::checkValue<FVector2D*>(L, 2);
				auto Offset2 = *Offset;
				auto ret = __newFBox2D();
				*ret = self->ShiftBy(Offset2);
				LuaObject::push<FBox2D>(L, "FBox2D", ret);
				return 1;
			}
			luaL_error(L, "call FBox2D::ShiftBy error, argc=%d", argc);
			return 0;
		}

		static int ToString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FBox2D*>(L, 1);
				auto ret = self->ToString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FBox2D::ToString error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FBox2D");
			LuaObject::addField(L, "Min", get_Min, set_Min, true);
			LuaObject::addField(L, "Max", get_Max, set_Max, true);
			LuaObject::addField(L, "bIsValid", get_bIsValid, set_bIsValid, true);
			LuaObject::addMethod(L, "ComputeSquaredDistanceToPoint", ComputeSquaredDistanceToPoint, true);
			LuaObject::addMethod(L, "ExpandBy", ExpandBy, true);
			LuaObject::addMethod(L, "GetArea", GetArea, true);
			LuaObject::addMethod(L, "GetCenter", GetCenter, true);
			LuaObject::addMethod(L, "GetCenterAndExtents", GetCenterAndExtents, true);
			LuaObject::addMethod(L, "GetClosestPointTo", GetClosestPointTo, true);
			LuaObject::addMethod(L, "GetExtent", GetExtent, true);
			LuaObject::addMethod(L, "GetSize", GetSize, true);
			LuaObject::addMethod(L, "Init", Init, true);
			LuaObject::addMethod(L, "Intersect", Intersect, true);
			LuaObject::addMethod(L, "IsInside", IsInside, true);
			LuaObject::addMethod(L, "ShiftBy", ShiftBy, true);
			LuaObject::addMethod(L, "ToString", ToString, true);
			LuaObject::finishType(L, "FBox2D", __ctor, __gc);
		}

	};

	struct FFloatRangeBoundWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FFloatRangeBound();
				LuaObject::push<FFloatRangeBound>(L, "FFloatRangeBound", self);
				return 1;
			}
			if (argc == 2) {
				auto InValue = LuaObject::checkValue<int>(L, 2);
				auto InValue2 = (const long long)InValue;
				auto self = new FFloatRangeBound(InValue2);
				LuaObject::push<FFloatRangeBound>(L, "FFloatRangeBound", self);
				return 1;
			}
			luaL_error(L, "call FFloatRangeBound() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FFloatRangeBound*>(L, 1);
			delete self;
			return 0;
		}

		static int Exclusive(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Value = LuaObject::checkValue<float>(L, 2);
				auto Value2 = (const float)Value;
				auto ret = __newFFloatRangeBound();
				*ret = FFloatRangeBound::Exclusive(Value2);
				LuaObject::push<FFloatRangeBound>(L, "FFloatRangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRangeBound::Exclusive error, argc=%d", argc);
			return 0;
		}

		static int Inclusive(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Value = LuaObject::checkValue<float>(L, 2);
				auto Value2 = (const float)Value;
				auto ret = __newFFloatRangeBound();
				*ret = FFloatRangeBound::Inclusive(Value2);
				LuaObject::push<FFloatRangeBound>(L, "FFloatRangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRangeBound::Inclusive error, argc=%d", argc);
			return 0;
		}

		static int Open(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto ret = __newFFloatRangeBound();
				*ret = FFloatRangeBound::Open();
				LuaObject::push<FFloatRangeBound>(L, "FFloatRangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRangeBound::Open error, argc=%d", argc);
			return 0;
		}

		static int FlipInclusion(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Bound = LuaObject::checkValue<FFloatRangeBound*>(L, 2);
				auto Bound2 = *Bound;
				auto ret = __newFFloatRangeBound();
				*ret = FFloatRangeBound::FlipInclusion(Bound2);
				LuaObject::push<FFloatRangeBound>(L, "FFloatRangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRangeBound::FlipInclusion error, argc=%d", argc);
			return 0;
		}

		static int MaxLower(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FFloatRangeBound*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FFloatRangeBound*>(L, 3);
				auto B2 = *B;
				auto ret = __newFFloatRangeBound();
				*ret = FFloatRangeBound::MaxLower(A2, B2);
				LuaObject::push<FFloatRangeBound>(L, "FFloatRangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRangeBound::MaxLower error, argc=%d", argc);
			return 0;
		}

		static int MaxUpper(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FFloatRangeBound*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FFloatRangeBound*>(L, 3);
				auto B2 = *B;
				auto ret = __newFFloatRangeBound();
				*ret = FFloatRangeBound::MaxUpper(A2, B2);
				LuaObject::push<FFloatRangeBound>(L, "FFloatRangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRangeBound::MaxUpper error, argc=%d", argc);
			return 0;
		}

		static int MinLower(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FFloatRangeBound*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FFloatRangeBound*>(L, 3);
				auto B2 = *B;
				auto ret = __newFFloatRangeBound();
				*ret = FFloatRangeBound::MinLower(A2, B2);
				LuaObject::push<FFloatRangeBound>(L, "FFloatRangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRangeBound::MinLower error, argc=%d", argc);
			return 0;
		}

		static int MinUpper(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FFloatRangeBound*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FFloatRangeBound*>(L, 3);
				auto B2 = *B;
				auto ret = __newFFloatRangeBound();
				*ret = FFloatRangeBound::MinUpper(A2, B2);
				LuaObject::push<FFloatRangeBound>(L, "FFloatRangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRangeBound::MinUpper error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FFloatRangeBound");
			LuaObject::addMethod(L, "Exclusive", Exclusive, false);
			LuaObject::addMethod(L, "Inclusive", Inclusive, false);
			LuaObject::addMethod(L, "Open", Open, false);
			LuaObject::addMethod(L, "FlipInclusion", FlipInclusion, false);
			LuaObject::addMethod(L, "MaxLower", MaxLower, false);
			LuaObject::addMethod(L, "MaxUpper", MaxUpper, false);
			LuaObject::addMethod(L, "MinLower", MinLower, false);
			LuaObject::addMethod(L, "MinUpper", MinUpper, false);
			LuaObject::finishType(L, "FFloatRangeBound", __ctor, __gc);
		}

	};

	struct FFloatRangeWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FFloatRange();
				LuaObject::push<FFloatRange>(L, "FFloatRange", self);
				return 1;
			}
			if (argc == 2) {
				auto A = LuaObject::checkValue<float>(L, 2);
				auto A2 = (const float)A;
				auto self = new FFloatRange(A2);
				LuaObject::push<FFloatRange>(L, "FFloatRange", self);
				return 1;
			}
			if (argc == 3) {
				auto A = LuaObject::checkValue<float>(L, 2);
				auto A2 = (const float)A;
				auto B = LuaObject::checkValue<float>(L, 3);
				auto B2 = (const float)B;
				auto self = new FFloatRange(A2, B2);
				LuaObject::push<FFloatRange>(L, "FFloatRange", self);
				return 1;
			}
			luaL_error(L, "call FFloatRange() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FFloatRange*>(L, 1);
			delete self;
			return 0;
		}

		static int Empty(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto ret = __newFFloatRange();
				*ret = FFloatRange::Empty();
				LuaObject::push<FFloatRange>(L, "FFloatRange", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRange::Empty error, argc=%d", argc);
			return 0;
		}

		static int Hull(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto X = LuaObject::checkValue<FFloatRange*>(L, 2);
				auto X2 = *X;
				auto Y = LuaObject::checkValue<FFloatRange*>(L, 3);
				auto Y2 = *Y;
				auto ret = __newFFloatRange();
				*ret = FFloatRange::Hull(X2, Y2);
				LuaObject::push<FFloatRange>(L, "FFloatRange", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRange::Hull error, argc=%d", argc);
			return 0;
		}

		static int Intersection(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto X = LuaObject::checkValue<FFloatRange*>(L, 2);
				auto X2 = *X;
				auto Y = LuaObject::checkValue<FFloatRange*>(L, 3);
				auto Y2 = *Y;
				auto ret = __newFFloatRange();
				*ret = FFloatRange::Intersection(X2, Y2);
				LuaObject::push<FFloatRange>(L, "FFloatRange", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRange::Intersection error, argc=%d", argc);
			return 0;
		}

		static int All(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto ret = __newFFloatRange();
				*ret = FFloatRange::All();
				LuaObject::push<FFloatRange>(L, "FFloatRange", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRange::All error, argc=%d", argc);
			return 0;
		}

		static int AtLeast(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Value = LuaObject::checkValue<float>(L, 2);
				auto Value2 = (const float)Value;
				auto ret = __newFFloatRange();
				*ret = FFloatRange::AtLeast(Value2);
				LuaObject::push<FFloatRange>(L, "FFloatRange", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRange::AtLeast error, argc=%d", argc);
			return 0;
		}

		static int AtMost(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Value = LuaObject::checkValue<float>(L, 2);
				auto Value2 = (const float)Value;
				auto ret = __newFFloatRange();
				*ret = FFloatRange::AtMost(Value2);
				LuaObject::push<FFloatRange>(L, "FFloatRange", ret);
				return 1;
			}
			luaL_error(L, "call FFloatRange::AtMost error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FFloatRange");
			LuaObject::addMethod(L, "Empty", Empty, false);
			LuaObject::addMethod(L, "Hull", Hull, false);
			LuaObject::addMethod(L, "Intersection", Intersection, false);
			LuaObject::addMethod(L, "All", All, false);
			LuaObject::addMethod(L, "AtLeast", AtLeast, false);
			LuaObject::addMethod(L, "AtMost", AtMost, false);
			LuaObject::finishType(L, "FFloatRange", __ctor, __gc);
		}

	};

	struct FInt32RangeBoundWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FInt32RangeBound();
				LuaObject::push<FInt32RangeBound>(L, "FInt32RangeBound", self);
				return 1;
			}
			if (argc == 2) {
				auto InValue = LuaObject::checkValue<int>(L, 2);
				auto InValue2 = (const long long)InValue;
				auto self = new FInt32RangeBound(InValue2);
				LuaObject::push<FInt32RangeBound>(L, "FInt32RangeBound", self);
				return 1;
			}
			luaL_error(L, "call FInt32RangeBound() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FInt32RangeBound*>(L, 1);
			delete self;
			return 0;
		}

		static int Exclusive(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Value = LuaObject::checkValue<int>(L, 2);
				auto Value2 = (const int)Value;
				auto ret = __newFInt32RangeBound();
				*ret = FInt32RangeBound::Exclusive(Value2);
				LuaObject::push<FInt32RangeBound>(L, "FInt32RangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FInt32RangeBound::Exclusive error, argc=%d", argc);
			return 0;
		}

		static int Inclusive(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Value = LuaObject::checkValue<int>(L, 2);
				auto Value2 = (const int)Value;
				auto ret = __newFInt32RangeBound();
				*ret = FInt32RangeBound::Inclusive(Value2);
				LuaObject::push<FInt32RangeBound>(L, "FInt32RangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FInt32RangeBound::Inclusive error, argc=%d", argc);
			return 0;
		}

		static int Open(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto ret = __newFInt32RangeBound();
				*ret = FInt32RangeBound::Open();
				LuaObject::push<FInt32RangeBound>(L, "FInt32RangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FInt32RangeBound::Open error, argc=%d", argc);
			return 0;
		}

		static int FlipInclusion(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Bound = LuaObject::checkValue<FInt32RangeBound*>(L, 2);
				auto Bound2 = *Bound;
				auto ret = __newFInt32RangeBound();
				*ret = FInt32RangeBound::FlipInclusion(Bound2);
				LuaObject::push<FInt32RangeBound>(L, "FInt32RangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FInt32RangeBound::FlipInclusion error, argc=%d", argc);
			return 0;
		}

		static int MaxLower(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FInt32RangeBound*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FInt32RangeBound*>(L, 3);
				auto B2 = *B;
				auto ret = __newFInt32RangeBound();
				*ret = FInt32RangeBound::MaxLower(A2, B2);
				LuaObject::push<FInt32RangeBound>(L, "FInt32RangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FInt32RangeBound::MaxLower error, argc=%d", argc);
			return 0;
		}

		static int MaxUpper(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FInt32RangeBound*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FInt32RangeBound*>(L, 3);
				auto B2 = *B;
				auto ret = __newFInt32RangeBound();
				*ret = FInt32RangeBound::MaxUpper(A2, B2);
				LuaObject::push<FInt32RangeBound>(L, "FInt32RangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FInt32RangeBound::MaxUpper error, argc=%d", argc);
			return 0;
		}

		static int MinLower(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FInt32RangeBound*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FInt32RangeBound*>(L, 3);
				auto B2 = *B;
				auto ret = __newFInt32RangeBound();
				*ret = FInt32RangeBound::MinLower(A2, B2);
				LuaObject::push<FInt32RangeBound>(L, "FInt32RangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FInt32RangeBound::MinLower error, argc=%d", argc);
			return 0;
		}

		static int MinUpper(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto A = LuaObject::checkValue<FInt32RangeBound*>(L, 2);
				auto A2 = *A;
				auto B = LuaObject::checkValue<FInt32RangeBound*>(L, 3);
				auto B2 = *B;
				auto ret = __newFInt32RangeBound();
				*ret = FInt32RangeBound::MinUpper(A2, B2);
				LuaObject::push<FInt32RangeBound>(L, "FInt32RangeBound", ret);
				return 1;
			}
			luaL_error(L, "call FInt32RangeBound::MinUpper error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FInt32RangeBound");
			LuaObject::addMethod(L, "Exclusive", Exclusive, false);
			LuaObject::addMethod(L, "Inclusive", Inclusive, false);
			LuaObject::addMethod(L, "Open", Open, false);
			LuaObject::addMethod(L, "FlipInclusion", FlipInclusion, false);
			LuaObject::addMethod(L, "MaxLower", MaxLower, false);
			LuaObject::addMethod(L, "MaxUpper", MaxUpper, false);
			LuaObject::addMethod(L, "MinLower", MinLower, false);
			LuaObject::addMethod(L, "MinUpper", MinUpper, false);
			LuaObject::finishType(L, "FInt32RangeBound", __ctor, __gc);
		}

	};

	struct FInt32RangeWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FInt32Range();
				LuaObject::push<FInt32Range>(L, "FInt32Range", self);
				return 1;
			}
			if (argc == 2) {
				auto A = LuaObject::checkValue<int>(L, 2);
				auto A2 = (const int)A;
				auto self = new FInt32Range(A2);
				LuaObject::push<FInt32Range>(L, "FInt32Range", self);
				return 1;
			}
			if (argc == 3) {
				auto A = LuaObject::checkValue<int>(L, 2);
				auto A2 = (const int)A;
				auto B = LuaObject::checkValue<int>(L, 3);
				auto B2 = (const int)B;
				auto self = new FInt32Range(A2, B2);
				LuaObject::push<FInt32Range>(L, "FInt32Range", self);
				return 1;
			}
			luaL_error(L, "call FInt32Range() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FInt32Range*>(L, 1);
			delete self;
			return 0;
		}

		static int Empty(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto ret = __newFInt32Range();
				*ret = FInt32Range::Empty();
				LuaObject::push<FInt32Range>(L, "FInt32Range", ret);
				return 1;
			}
			luaL_error(L, "call FInt32Range::Empty error, argc=%d", argc);
			return 0;
		}

		static int Hull(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto X = LuaObject::checkValue<FInt32Range*>(L, 2);
				auto X2 = *X;
				auto Y = LuaObject::checkValue<FInt32Range*>(L, 3);
				auto Y2 = *Y;
				auto ret = __newFInt32Range();
				*ret = FInt32Range::Hull(X2, Y2);
				LuaObject::push<FInt32Range>(L, "FInt32Range", ret);
				return 1;
			}
			luaL_error(L, "call FInt32Range::Hull error, argc=%d", argc);
			return 0;
		}

		static int Intersection(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 3) {
				auto X = LuaObject::checkValue<FInt32Range*>(L, 2);
				auto X2 = *X;
				auto Y = LuaObject::checkValue<FInt32Range*>(L, 3);
				auto Y2 = *Y;
				auto ret = __newFInt32Range();
				*ret = FInt32Range::Intersection(X2, Y2);
				LuaObject::push<FInt32Range>(L, "FInt32Range", ret);
				return 1;
			}
			luaL_error(L, "call FInt32Range::Intersection error, argc=%d", argc);
			return 0;
		}

		static int All(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto ret = __newFInt32Range();
				*ret = FInt32Range::All();
				LuaObject::push<FInt32Range>(L, "FInt32Range", ret);
				return 1;
			}
			luaL_error(L, "call FInt32Range::All error, argc=%d", argc);
			return 0;
		}

		static int AtLeast(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Value = LuaObject::checkValue<int>(L, 2);
				auto Value2 = (const int)Value;
				auto ret = __newFInt32Range();
				*ret = FInt32Range::AtLeast(Value2);
				LuaObject::push<FInt32Range>(L, "FInt32Range", ret);
				return 1;
			}
			luaL_error(L, "call FInt32Range::AtLeast error, argc=%d", argc);
			return 0;
		}

		static int AtMost(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto Value = LuaObject::checkValue<int>(L, 2);
				auto Value2 = (const int)Value;
				auto ret = __newFInt32Range();
				*ret = FInt32Range::AtMost(Value2);
				LuaObject::push<FInt32Range>(L, "FInt32Range", ret);
				return 1;
			}
			luaL_error(L, "call FInt32Range::AtMost error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FInt32Range");
			LuaObject::addMethod(L, "Empty", Empty, false);
			LuaObject::addMethod(L, "Hull", Hull, false);
			LuaObject::addMethod(L, "Intersection", Intersection, false);
			LuaObject::addMethod(L, "All", All, false);
			LuaObject::addMethod(L, "AtLeast", AtLeast, false);
			LuaObject::addMethod(L, "AtMost", AtMost, false);
			LuaObject::finishType(L, "FInt32Range", __ctor, __gc);
		}

	};

	struct FFloatIntervalWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FFloatInterval();
				LuaObject::push<FFloatInterval>(L, "FFloatInterval", self);
				return 1;
			}
			if (argc == 3) {
				auto InMin = LuaObject::checkValue<float>(L, 2);
				auto InMax = LuaObject::checkValue<float>(L, 3);
				auto self = new FFloatInterval(InMin, InMax);
				LuaObject::push<FFloatInterval>(L, "FFloatInterval", self);
				return 1;
			}
			luaL_error(L, "call FFloatInterval() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FFloatInterval*>(L, 1);
			delete self;
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FFloatInterval");
			LuaObject::finishType(L, "FFloatInterval", __ctor, __gc);
		}

	};

	struct FInt32IntervalWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FInt32Interval();
				LuaObject::push<FInt32Interval>(L, "FInt32Interval", self);
				return 1;
			}
			if (argc == 3) {
				auto InMin = LuaObject::checkValue<int>(L, 2);
				auto InMax = LuaObject::checkValue<int>(L, 3);
				auto self = new FInt32Interval(InMin, InMax);
				LuaObject::push<FInt32Interval>(L, "FInt32Interval", self);
				return 1;
			}
			luaL_error(L, "call FInt32Interval() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FInt32Interval*>(L, 1);
			delete self;
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FInt32Interval");
			LuaObject::finishType(L, "FInt32Interval", __ctor, __gc);
		}

	};

	struct FPrimaryAssetTypeWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FPrimaryAssetType();
				LuaObject::push<FPrimaryAssetType>(L, "FPrimaryAssetType", self);
				return 1;
			}
			if (argc == 2) {
				auto InName = LuaObject::checkValue<int>(L, 2);
				auto InName2 = (EName)InName;
				auto self = new FPrimaryAssetType(InName2);
				LuaObject::push<FPrimaryAssetType>(L, "FPrimaryAssetType", self);
				return 1;
			}
			luaL_error(L, "call FPrimaryAssetType() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FPrimaryAssetType*>(L, 1);
			delete self;
			return 0;
		}

		static int IsValid(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FPrimaryAssetType*>(L, 1);
				auto ret = self->IsValid();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FPrimaryAssetType::IsValid error, argc=%d", argc);
			return 0;
		}

		static int ToString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FPrimaryAssetType*>(L, 1);
				auto ret = self->ToString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FPrimaryAssetType::ToString error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FPrimaryAssetType");
			LuaObject::addMethod(L, "IsValid", IsValid, true);
			LuaObject::addMethod(L, "ToString", ToString, true);
			LuaObject::finishType(L, "FPrimaryAssetType", __ctor, __gc);
		}

	};

	struct FPrimaryAssetIdWrapper {

		static int __ctor(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = new FPrimaryAssetId();
				LuaObject::push<FPrimaryAssetId>(L, "FPrimaryAssetId", self);
				return 1;
			}
			if (argc == 2) {
				auto InString = LuaObject::checkValue<FString>(L, 2);
				auto self = new FPrimaryAssetId(InString);
				LuaObject::push<FPrimaryAssetId>(L, "FPrimaryAssetId", self);
				return 1;
			}
			luaL_error(L, "call FPrimaryAssetId() error, argc=%d", argc);
			return 0;
		}

		static int __gc(lua_State* L) {
			auto self = LuaObject::checkValue<FPrimaryAssetId*>(L, 1);
			delete self;
			return 0;
		}

		static int get_PrimaryAssetType(lua_State* L) {
			auto self = LuaObject::checkValue<FPrimaryAssetId*>(L, 1);
			LuaObject::push<FPrimaryAssetType>(L, "FPrimaryAssetType", &self->PrimaryAssetType);
			return 1;
		}

		static int set_PrimaryAssetType(lua_State* L) {
			auto self = LuaObject::checkValue<FPrimaryAssetId*>(L, 1);
			auto a1 = LuaObject::checkValue<FPrimaryAssetType*>(L, 2);
			self->PrimaryAssetType = *a1;
			LuaObject::push<FPrimaryAssetType>(L, "FPrimaryAssetType", a1);
			return 1;
		}

		static int IsValid(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FPrimaryAssetId*>(L, 1);
				auto ret = self->IsValid();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FPrimaryAssetId::IsValid error, argc=%d", argc);
			return 0;
		}

		static int ToString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 1) {
				auto self = LuaObject::checkValue<FPrimaryAssetId*>(L, 1);
				auto ret = self->ToString();
				LuaObject::push(L, ret);
				return 1;
			}
			luaL_error(L, "call FPrimaryAssetId::ToString error, argc=%d", argc);
			return 0;
		}

		static int FromString(lua_State* L) {
			auto argc = lua_gettop(L);
			if (argc == 2) {
				auto String = LuaObject::checkValue<FString>(L, 2);
				auto ret = __newFPrimaryAssetId();
				*ret = FPrimaryAssetId::FromString(String);
				LuaObject::push<FPrimaryAssetId>(L, "FPrimaryAssetId", ret);
				return 1;
			}
			luaL_error(L, "call FPrimaryAssetId::FromString error, argc=%d", argc);
			return 0;
		}

		static void bind(lua_State* L) {
			LuaObject::newType(L, "FPrimaryAssetId");
			LuaObject::addField(L, "PrimaryAssetType", get_PrimaryAssetType, set_PrimaryAssetType, true);
			LuaObject::addMethod(L, "IsValid", IsValid, true);
			LuaObject::addMethod(L, "ToString", ToString, true);
			LuaObject::addMethod(L, "FromString", FromString, false);
			LuaObject::finishType(L, "FPrimaryAssetId", __ctor, __gc);
		}

	};

	int LuaWrapper::pushValue(lua_State* L, UStructProperty* p, UScriptStruct* uss, uint8* parms) {
		auto vptr = _pushStructMap.Find(uss);
		if (vptr != nullptr) {
			(*vptr)(L, p, parms);
			return 1;
		} else {
			return 0;
		}
	}

	int LuaWrapper::checkValue(lua_State* L, UStructProperty* p, UScriptStruct* uss, uint8* parms, int i) {
		auto vptr = _checkStructMap.Find(uss);
		if (vptr != nullptr) {
			(*vptr)(L, p, parms, i);
			return 1;
		} else {
			return 0;
		}
	}

	void LuaWrapper::init(lua_State* L) {
		FRotatorStruct = TBaseStructure<FRotator>::Get();
		_pushStructMap.Add(FRotatorStruct, __pushFRotator);
		_checkStructMap.Add(FRotatorStruct, __checkFRotator);
		FTransformStruct = TBaseStructure<FTransform>::Get();
		_pushStructMap.Add(FTransformStruct, __pushFTransform);
		_checkStructMap.Add(FTransformStruct, __checkFTransform);
		FLinearColorStruct = TBaseStructure<FLinearColor>::Get();
		_pushStructMap.Add(FLinearColorStruct, __pushFLinearColor);
		_checkStructMap.Add(FLinearColorStruct, __checkFLinearColor);
		FColorStruct = TBaseStructure<FColor>::Get();
		_pushStructMap.Add(FColorStruct, __pushFColor);
		_checkStructMap.Add(FColorStruct, __checkFColor);
		FVectorStruct = TBaseStructure<FVector>::Get();
		_pushStructMap.Add(FVectorStruct, __pushFVector);
		_checkStructMap.Add(FVectorStruct, __checkFVector);
		FVector2DStruct = TBaseStructure<FVector2D>::Get();
		_pushStructMap.Add(FVector2DStruct, __pushFVector2D);
		_checkStructMap.Add(FVector2DStruct, __checkFVector2D);
		FRandomStreamStruct = TBaseStructure<FRandomStream>::Get();
		_pushStructMap.Add(FRandomStreamStruct, __pushFRandomStream);
		_checkStructMap.Add(FRandomStreamStruct, __checkFRandomStream);
		FGuidStruct = TBaseStructure<FGuid>::Get();
		_pushStructMap.Add(FGuidStruct, __pushFGuid);
		_checkStructMap.Add(FGuidStruct, __checkFGuid);
		FBox2DStruct = TBaseStructure<FBox2D>::Get();
		_pushStructMap.Add(FBox2DStruct, __pushFBox2D);
		_checkStructMap.Add(FBox2DStruct, __checkFBox2D);
		FFloatRangeBoundStruct = TBaseStructure<FFloatRangeBound>::Get();
		_pushStructMap.Add(FFloatRangeBoundStruct, __pushFFloatRangeBound);
		_checkStructMap.Add(FFloatRangeBoundStruct, __checkFFloatRangeBound);
		FFloatRangeStruct = TBaseStructure<FFloatRange>::Get();
		_pushStructMap.Add(FFloatRangeStruct, __pushFFloatRange);
		_checkStructMap.Add(FFloatRangeStruct, __checkFFloatRange);
		FInt32RangeBoundStruct = TBaseStructure<FInt32RangeBound>::Get();
		_pushStructMap.Add(FInt32RangeBoundStruct, __pushFInt32RangeBound);
		_checkStructMap.Add(FInt32RangeBoundStruct, __checkFInt32RangeBound);
		FInt32RangeStruct = TBaseStructure<FInt32Range>::Get();
		_pushStructMap.Add(FInt32RangeStruct, __pushFInt32Range);
		_checkStructMap.Add(FInt32RangeStruct, __checkFInt32Range);
		FFloatIntervalStruct = TBaseStructure<FFloatInterval>::Get();
		_pushStructMap.Add(FFloatIntervalStruct, __pushFFloatInterval);
		_checkStructMap.Add(FFloatIntervalStruct, __checkFFloatInterval);
		FInt32IntervalStruct = TBaseStructure<FInt32Interval>::Get();
		_pushStructMap.Add(FInt32IntervalStruct, __pushFInt32Interval);
		_checkStructMap.Add(FInt32IntervalStruct, __checkFInt32Interval);
		FPrimaryAssetTypeStruct = TBaseStructure<FPrimaryAssetType>::Get();
		_pushStructMap.Add(FPrimaryAssetTypeStruct, __pushFPrimaryAssetType);
		_checkStructMap.Add(FPrimaryAssetTypeStruct, __checkFPrimaryAssetType);
		FPrimaryAssetIdStruct = TBaseStructure<FPrimaryAssetId>::Get();
		_pushStructMap.Add(FPrimaryAssetIdStruct, __pushFPrimaryAssetId);
		_checkStructMap.Add(FPrimaryAssetIdStruct, __checkFPrimaryAssetId);

		FRotatorWrapper::bind(L);
		FTransformWrapper::bind(L);
		FLinearColorWrapper::bind(L);
		FColorWrapper::bind(L);
		FVectorWrapper::bind(L);
		FVector2DWrapper::bind(L);
		FRandomStreamWrapper::bind(L);
		FGuidWrapper::bind(L);
		FBox2DWrapper::bind(L);
		FFloatRangeBoundWrapper::bind(L);
		FFloatRangeWrapper::bind(L);
		FInt32RangeBoundWrapper::bind(L);
		FInt32RangeWrapper::bind(L);
		FFloatIntervalWrapper::bind(L);
		FInt32IntervalWrapper::bind(L);
		FPrimaryAssetTypeWrapper::bind(L);
		FPrimaryAssetIdWrapper::bind(L);
	}

}
