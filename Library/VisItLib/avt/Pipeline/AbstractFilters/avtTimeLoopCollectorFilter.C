/*****************************************************************************
*
* Copyright (c) 2000 - 2010, Lawrence Livermore National Security, LLC
* Produced at the Lawrence Livermore National Laboratory
* LLNL-CODE-400124
* All rights reserved.
*
* This file is  part of VisIt. For  details, see https://visit.llnl.gov/.  The
* full copyright notice is contained in the file COPYRIGHT located at the root
* of the VisIt distribution or at http://www.llnl.gov/visit/copyright.html.
*
* Redistribution  and  use  in  source  and  binary  forms,  with  or  without
* modification, are permitted provided that the following conditions are met:
*
*  - Redistributions of  source code must  retain the above  copyright notice,
*    this list of conditions and the disclaimer below.
*  - Redistributions in binary form must reproduce the above copyright notice,
*    this  list of  conditions  and  the  disclaimer (as noted below)  in  the
*    documentation and/or other materials provided with the distribution.
*  - Neither the name of  the LLNS/LLNL nor the names of  its contributors may
*    be used to endorse or promote products derived from this software without
*    specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT  HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR  IMPLIED WARRANTIES, INCLUDING,  BUT NOT  LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND  FITNESS FOR A PARTICULAR  PURPOSE
* ARE  DISCLAIMED. IN  NO EVENT  SHALL LAWRENCE  LIVERMORE NATIONAL  SECURITY,
* LLC, THE  U.S.  DEPARTMENT OF  ENERGY  OR  CONTRIBUTORS BE  LIABLE  FOR  ANY
* DIRECT,  INDIRECT,   INCIDENTAL,   SPECIAL,   EXEMPLARY,  OR   CONSEQUENTIAL
* DAMAGES (INCLUDING, BUT NOT  LIMITED TO, PROCUREMENT OF  SUBSTITUTE GOODS OR
* SERVICES; LOSS OF  USE, DATA, OR PROFITS; OR  BUSINESS INTERRUPTION) HOWEVER
* CAUSED  AND  ON  ANY  THEORY  OF  LIABILITY,  WHETHER  IN  CONTRACT,  STRICT
* LIABILITY, OR TORT  (INCLUDING NEGLIGENCE OR OTHERWISE)  ARISING IN ANY  WAY
* OUT OF THE  USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
* DAMAGE.
*
*****************************************************************************/

// ************************************************************************* //
//                      avtTimeLoopCollectorFilter.C                         //
// ************************************************************************* //

#include <avtTimeLoopCollectorFilter.h>

#include <avtTimeLoopFilter.h>


// ****************************************************************************
//  Method: avtTimeLoopCollectorFilter constructor
//
//  Purpose:
//      Defines the destructor.  Note: this should not be inlined in the header
//      because it causes problems for certain compilers.
//
//  Programmer: Hank Childs
//  Creation:   January 22, 2008
//
// ****************************************************************************

avtTimeLoopCollectorFilter::avtTimeLoopCollectorFilter()
{
    ;
}


// ****************************************************************************
//  Method: avtTimeLoopCollectorFilter destructor
//
//  Purpose:
//      Defines the destructor.  Note: this should not be inlined in the header
//      because it causes problems for certain compilers.
//
//  Programmer: Hank Childs
//  Creation:   January 22, 2008 
//
// ****************************************************************************

avtTimeLoopCollectorFilter::~avtTimeLoopCollectorFilter()
{
    ;
}


// ****************************************************************************
//  Method: avtTimeLoopCollectorFilter::CreateFinalOutput
//
//  Purpose:  
//      Called when all of the time slices have been iterated over.  This then
//      turns around and calls the derived types "ExecuteAllTimesteps" method.
//
//  Programmer: Hank Childs
//  Creation:   January 22, 2008
//
// ****************************************************************************

void
avtTimeLoopCollectorFilter::CreateFinalOutput()
{
    avtDataTree_p output = ExecuteAllTimesteps(trees);
    SetOutputDataTree(output);
    trees.clear();
}


// ****************************************************************************
//  Method: avtTimeLoopCollectorFilter::Execute
//
//  Purpose:  
//      Called when a data set is ready to be executed on.  This stores the
//      data set for later use.
//
//  Programmer: Hank Childs
//  Creation:   January 22, 2008
//
// ****************************************************************************

void
avtTimeLoopCollectorFilter::Execute()
{
    trees.push_back(GetInputDataTree());
}


// ****************************************************************************
//  Method: avtTimeLoopCollectorFilter::ReleaseData
//
//  Purpose:
//      Makes the output release any data that it has as a memory savings.
//
//  Programmer: Hank Childs
//  Creation:   January 22, 2008
//
// ****************************************************************************

void
avtTimeLoopCollectorFilter::ReleaseData(void)
{
    trees.clear();
    avtFilter::ReleaseData();    
}
