/*

Imebra 2011 build 2012-12-19_20-05-13

Imebra: a C++ Dicom library

Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010 by Paolo Brandoli
All rights reserved.

Redistribution and use in source and binary forms, with or without modification,
 are permitted provided that the following conditions are met:
- Redistributions of source code must retain the above copyright notice, this
  list of conditions and the following disclaimer.
- Redistributions in binary form must reproduce the above copyright notice,
  this list of conditions and the following disclaimer in the documentation
  and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE FREEBSD PROJECT ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES,
INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE FREEBSD PROJECT OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA,
OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

The views and conclusions contained in the software and documentation are those of the authors
 and should not be interpreted as representing official policies, either expressed or implied,
 of the Imebra Project.

Imebra is available at http://imebra.com



*/

/*! \file charsetsList.cpp
    \brief Implementation of the basic class for the classes that handles the charsets.

*/

#include "../../base/include/exception.h"
#include "../include/charsetsList.h"


namespace puntoexe
{

namespace imebra
{

namespace charsetsList
{

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//
//
//
// charsetsList
//
//
//
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//
//
// Copy the charsets in the list into the local list.
// An exception is thrown if a mismatch in the default
//  charset is detected
//
//
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
void updateCharsets(const tCharsetsList* pCharsetsList, tCharsetsList* pDestinationCharsetsList)
{
	PUNTOEXE_FUNCTION_START(L"charsetsList::updateCharsets");

	// Check the default charset
	///////////////////////////////////////////////////////////
	if(!pCharsetsList->empty() && !pDestinationCharsetsList->empty() && pCharsetsList->front() != pDestinationCharsetsList->front())
	{
		PUNTOEXE_THROW(charsetListExceptionDiffDefault, "Different default charsets");
	}

	// Copy the charsets in the local list (if they are not
	//  already there)
	///////////////////////////////////////////////////////////
	for(const auto & scanCharsets : *pCharsetsList)
	{
		bool bExist = false;
		for(auto & scanExistingCharsets : *pDestinationCharsetsList)
		{
			if(scanCharsets == scanExistingCharsets)
			{
				bExist = true;
				break;
			}
		}
		if(!bExist)
		{
			pDestinationCharsetsList->push_back(scanCharsets);
		}
	}

	PUNTOEXE_FUNCTION_END();
}



///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
//
//
// Copy the charsets from the local list into the
//  specified list
//
//
///////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////
void copyCharsets(const tCharsetsList* pSourceCharsetsList, tCharsetsList* pDestinationCharsetsList)
{
	PUNTOEXE_FUNCTION_START(L"charsetsList::copyCharsets");

	for(const auto & scanCharsets : *pSourceCharsetsList)
	{
		pDestinationCharsetsList->push_back(scanCharsets);
	}

	PUNTOEXE_FUNCTION_END();
}

} // namespace charsetsList

} // namespace imebra

} // namespace puntoexe
