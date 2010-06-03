/* +---------------------------------------------------------------------------+
   |          The Mobile Robot Programming Toolkit (MRPT) C++ library          |
   |                                                                           |
   |                   http://mrpt.sourceforge.net/                            |
   |                                                                           |
   |   Copyright (C) 2005-2010  University of Malaga                           |
   |                                                                           |
   |    This software was written by the Machine Perception and Intelligent    |
   |      Robotics Lab, University of Malaga (Spain).                          |
   |    Contact: Jose-Luis Blanco  <jlblanco@ctima.uma.es>                     |
   |                                                                           |
   |  This file is part of the MRPT project.                                   |
   |                                                                           |
   |     MRPT is free software: you can redistribute it and/or modify          |
   |     it under the terms of the GNU General Public License as published by  |
   |     the Free Software Foundation, either version 3 of the License, or     |
   |     (at your option) any later version.                                   |
   |                                                                           |
   |   MRPT is distributed in the hope that it will be useful,                 |
   |     but WITHOUT ANY WARRANTY; without even the implied warranty of        |
   |     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         |
   |     GNU General Public License for more details.                          |
   |                                                                           |
   |     You should have received a copy of the GNU General Public License     |
   |     along with MRPT.  If not, see <http://www.gnu.org/licenses/>.         |
   |                                                                           |
   +---------------------------------------------------------------------------+ */

#include <mrpt/base.h>  // Precompiled headers

#include <mrpt/utils/TCamera.h>
#include <mrpt/math/ops_matrices.h>  // For "<<" ">>" operators.

using namespace mrpt::utils;
using namespace mrpt::math;
using namespace std;


/* Implements serialization for the TCamera struct as it will be included within CObservations objects */
IMPLEMENTS_SERIALIZABLE( TCamera, CSerializable, mrpt::utils )

// WriteToStream
void TCamera::writeToStream( CStream &out, int *version ) const
{
	if( version )
		*version = 2;
	else
	{
		out << focalLengthMeters;
		for(unsigned int k = 0; k < 5; k++) out << dist[k];
		out << intrinsicParams;
		// version 0 did serialize here a "CMatrixDouble15"
		out << nrows << ncols; // New in v2
	} // end else
}

// ReadFromStream
void TCamera::readFromStream( CStream &in, int version )
{
	switch( version )
	{
	case 0:
	case 1:
	case 2:
		{
			in >> focalLengthMeters;

			for(unsigned int k = 0; k < 5; k++)
				in >> dist[k];

			in >> intrinsicParams;

			if (version==0)
			{
				CMatrixDouble15 __distortionParams;
				in >> __distortionParams;
			}

			if (version>=2)
				in >> nrows >> ncols;
			else {
				nrows = 480;
				ncols = 640;
			}


		} break;
	default:
		MRPT_THROW_UNKNOWN_SERIALIZATION_VERSION( version )
	}
}


/**  Save as a config block:
  *  \code
  *  [SECTION]
  *  resolution = NCOLS NROWS
  *  cx         = CX
  *  cy         = CY
  *  fx         = FX
  *  fy         = FY
  *  dist       = K1 K2 T1 T2 T3
  *  focal_length = FOCAL_LENGTH
  *  \endcode
  */
void TCamera::saveToConfigFile(const std::string &section,  mrpt::utils::CConfigFileBase &cfg ) const
{
	cfg.write(section,"resolution",format("[%u %u]",(unsigned int)ncols,(unsigned int)nrows));
	cfg.write(section,"cx", cx() );
	cfg.write(section,"cy", cy() );
	cfg.write(section,"fx", fx() );
	cfg.write(section,"fy", fy() );
	cfg.write(section,"dist", format("[%e %e %e %e %e]", dist[0],dist[1],dist[2],dist[3],dist[4] ) );
	cfg.write(section,"focal_length", focalLengthMeters );
}

/**  Load all the params from a config source, in the format described in saveToConfigFile()
  */
void TCamera::loadFromConfigFile(const std::string &section,  const mrpt::utils::CConfigFileBase &cfg )
{
	vector<uint64_t>  out_res;
	cfg.read_vector(section,"resolution",vector<uint64_t>(),out_res,true);
	if (out_res.size()!=2) THROW_EXCEPTION("Expected 2-length vector in field 'resolution'");
	ncols = out_res[0];
	nrows = out_res[1];

	setIntrinsicParamsFromValues(
		cfg.read_double(section,"fx",0, true),
		cfg.read_double(section,"fy",0, true),
		cfg.read_double(section,"cx",0, true),
		cfg.read_double(section,"cy",0, true)
		);

	vector_double dists;
	cfg.read_vector(section,"dist",vector_double(), dists, true);
	if (dists.size()!=4 && dists.size()!=5) THROW_EXCEPTION("Expected 4 or 5-length vector in field 'dist'");

	dist.assign(0);
	for (size_t i=0;i<dists.size();i++)
		dist[i] = dists[i];

	focalLengthMeters = cfg.read_double(section,"focal_length",0.002, false /* optional value */ );

}
