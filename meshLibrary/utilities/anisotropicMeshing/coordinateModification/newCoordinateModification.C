/*---------------------------------------------------------------------------*\
  =========                 |
  \\      /  F ield         | cfMesh: A library for mesh generation
   \\    /   O peration     |
    \\  /    A nd           | Author: Franjo Juretic (franjo.juretic@c-fields.com)
     \\/     M anipulation  | Copyright (C) Creative Fields, Ltd.
-------------------------------------------------------------------------------
License
    This file is part of cfMesh.

    cfMesh is free software; you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation; either version 3 of the License, or (at your
    option) any later version.

    cfMesh is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
    FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
    for more details.

    You should have received a copy of the GNU General Public License
    along with cfMesh.  If not, see <http://www.gnu.org/licenses/>.

\*---------------------------------------------------------------------------*/

#include "coordinateModification.H"
#include "dictionary.H"
#include "error.H"
#include "addToRunTimeSelectionTable.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * Member Functions  * * * * * * * * * * * * * //

autoPtr<coordinateModification> coordinateModification::New
(
    const word& name,
    const dictionary& dict
)
{
    if (debug)
    {
        Info << "coordinateModification::New(const word&, const dictionary&) : "
             << "constructing coordinateModification" << endl;
    }

    // Get type name from dictionary (or fallback to this base class name)
    word cmType(typeName_());
    if (dict.found("type"))
    {
        dict.lookup("type") >> cmType;
    }

    auto* ctorPtr = dictionaryConstructorTable(cmType);

    if (!ctorPtr)
    {
        FatalIOErrorInLookup
        (
            dict,
            "coordinateModification::New(const word&, const dictionary&)",
            cmType,
            *dictionaryConstructorTablePtr_
        ) << exit(FatalIOError);
    }

    return autoPtr<coordinateModification>(ctorPtr(name, dict));
}

} // End namespace Foam

// ************************************************************************* //
