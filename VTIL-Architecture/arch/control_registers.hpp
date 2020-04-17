// Copyright (c) 2020 Can Boluk and contributors of the VTIL Project   
// All rights reserved.   
//    
// Redistribution and use in source and binary forms, with or without   
// modification, are permitted provided that the following conditions are met: 
//    
// 1. Redistributions of source code must retain the above copyright notice,   
//    this list of conditions and the following disclaimer.   
// 2. Redistributions in binary form must reproduce the above copyright   
//    notice, this list of conditions and the following disclaimer in the   
//    documentation and/or other materials provided with the distribution.   
// 3. Neither the name of mosquitto nor the names of its   
//    contributors may be used to endorse or promote products derived from   
//    this software without specific prior written permission.   
//    
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE   
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE  
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE   
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR   
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF   
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS   
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN   
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)   
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE  
// POSSIBILITY OF SUCH DAMAGE.        
//
#pragma once
#include <mutex>
#include <optional>
#include <vtil/amd64>

// The x86_reg value that equates to the first user-defined control register
// and a handy macro to get the value for Nth instance.
//
#define X86_REG_VCR(n) x86_reg( unsigned( X86_REG_ENDING ) + (n + 1) )
static constexpr x86_reg X86_REG_VCR0 = X86_REG_VCR( 0 );

namespace vtil::arch
{
	// Describes the properites of a user-defined control register.
	//
	struct control_register_desc
	{
		// Name of the register.
		//
		std::string identifier;

		// Whether this control register is read only or not.
		//
		bool read_only = false;
	};

	// Looks up the descriptor for the given control register.
	//
	std::optional<control_register_desc> lookup_control_register( x86_reg reg );

	// Creates a new control register based on the descriptor and returns the
	// x86_reg value that it is mapped to.
	//
	x86_reg create_control_register( const control_register_desc& descriptor );
};