/*
 * Copyright (c) 2017. tangzx(love.tangzx@qq.com)
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

package com.tang.intellij.lua.stubs

import com.intellij.psi.stubs.IndexSink
import com.intellij.psi.stubs.StubElement
import com.intellij.psi.stubs.StubInputStream
import com.intellij.psi.stubs.StubOutputStream
import com.tang.intellij.lua.psi.LuaLiteralExpr
import com.tang.intellij.lua.psi.impl.LuaLiteralExprImpl

class LuaLiteralElementType
    : LuaStubElementType<LuaLiteralExprStub, LuaLiteralExpr>("LITERAL_EXPR") {
    override fun serialize(stub: LuaLiteralExprStub, stream: StubOutputStream) {

    }

    override fun createStub(expr: LuaLiteralExpr, parentStub: StubElement<*>?): LuaLiteralExprStub {
        return LuaLiteralExprStub(parentStub, this)
    }

    override fun deserialize(stream: StubInputStream, parentStub: StubElement<*>?): LuaLiteralExprStub {
        return LuaLiteralExprStub(parentStub, this)
    }

    override fun indexStub(stub: LuaLiteralExprStub, sink: IndexSink) {

    }

    override fun createPsi(stub: LuaLiteralExprStub): LuaLiteralExpr {
        return LuaLiteralExprImpl(stub, this)
    }
}

class LuaLiteralExprStub(parent: StubElement<*>?, type: LuaStubElementType<*, *>)
    : LuaStubBase<LuaLiteralExpr>(parent, type)