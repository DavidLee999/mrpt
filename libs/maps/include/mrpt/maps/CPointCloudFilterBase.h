/* +---------------------------------------------------------------------------+
|                     Mobile Robot Programming Toolkit (MRPT)               |
|                          http://www.mrpt.org/                             |
|                                                                           |
| Copyright (c) 2005-2017, Individual contributors, see AUTHORS file        |
| See: http://www.mrpt.org/Authors - All rights reserved.                   |
| Released under BSD License. See details in http://www.mrpt.org/License    |
+---------------------------------------------------------------------------+ */
#pragma once

#include <mrpt/system/datetime.h>
#include <mrpt/maps/link_pragmas.h>
#include <mrpt/otherlibs/stlplus/smart_ptr.hpp>

namespace mrpt
{
	namespace poses { class CPose3D; }
	namespace maps { class CPointsMap; }

	namespace maps
	{
		/** Virtual base class for all point-cloud filtering algorithm. See derived classes for implementations.
		* \sa CPointsMap
		* \ingroup mrpt_maps_grp
		*/
		class MAPS_IMPEXP CPointCloudFilterBase
		{
		public:
			CPointCloudFilterBase();
			virtual ~CPointCloudFilterBase();

			/** Apply the filtering algorithm to the pointcloud. */
			virtual void filter(
				mrpt::maps::CPointsMap * inout_pointcloud,            //!< [in,out] The input pointcloud, which will be modified upon return after filtering.
				const mrpt::system::TTimeStamp pc_timestamp,          //!< [in] The timestamp of the input pointcloud
				const mrpt::poses::CPose3D * pc_reference_pose = NULL //!< [in] If NULL, the PC is assumed to be given in global coordinates. Otherwise, it will be transformed from local coordinates to global using this transformation.
			) = 0;
		};

		typedef stlplus::smart_ptr<CPointCloudFilterBase> CPointCloudFilterBasePtr;

	}
} // End of namespace
