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

#ifndef opengl_CMesh_H
#define opengl_CMesh_H

#include <mrpt/opengl/CRenderizable.h>
#include <mrpt/math/CMatrix.h>
#include <mrpt/utils/CImage.h>
#include <mrpt/utils/color_maps.h>
#include <mrpt/opengl/CSetOfTriangles.h>

namespace mrpt
{
	namespace opengl
	{
		class OPENGL_IMPEXP CMesh;

		// This must be added to any CSerializable derived class:
		DEFINE_SERIALIZABLE_PRE_CUSTOM_BASE_LINKAGE( CMesh, CRenderizable, OPENGL_IMPEXP )

		/** A set of connected colored triangles.
		  *  This class can be used to draw any solid, arbitrarily complex object (without textures).
		  *  \sa opengl::COpenGLScene
		  */
		class OPENGL_IMPEXP CMesh : public CRenderizable
		{
			DEFINE_SERIALIZABLE( CMesh )
		protected:
			mrpt::utils::CImage		m_textureImage;

			bool						m_enableTransparency;
			bool						m_colorFromZ;
			bool						m_isWireFrame;

			math::CMatrix		Z;		//!< Z(x,y): Z-coordinate of the point (x,y)
			math::CMatrix		mask;
			math::CMatrix		U, V;	//!< Texture coordinates
			mutable math::CMatrix		C;		//!< Color [0,1] for each cell, updated by updateColorsMatrix

			mrpt::utils::TColormap		m_colorMap; //!< Used when m_colorFromZ is true

			mutable bool	m_modified_Z;		//!< Whether C is not up-to-date wrt to Z

			void updateColorsMatrix() const;	//!< Called internally to assure C is updated.
			void updateTriangles() const;		//!< Called internally to assure the triangle list is updated.
			void updatePolygons() const;	//<!Called internally to assure that the polygon list is updated.

			float xMin,xMax,yMin,yMax;	//!< Mesh bounds
			mutable std::vector<CSetOfTriangles::TTriangle> actualMesh;	//!< List of triangles in the mesh
			mutable bool trianglesUpToDate;		//!<Whether the actual mesh needs to be recalculated
			mutable bool polygonsUpToDate;	//<!Whether the polygon mesh (auxiliary structure for ray tracing) needs to be recalculated
			mutable std::vector<mrpt::math::TPolygonWithPlane> tmpPolys;

		public:
			void setGridLimits(float xmin,float xmax, float ymin, float ymax)
			{
				xMin=xmin; xMax = xmax;
				yMin=ymin; yMax = ymax;
			}

			void getGridLimits(float &xmin,float &xmax, float &ymin, float &ymax) const
			{
				xmin=xMin; xmax=xMax;
				ymin=yMin; ymax=yMax;
			}

			void enableTransparency( bool v )	{ m_enableTransparency = v; }
			void enableWireFrame( bool v ) 		{ m_isWireFrame = v; }
			void enableColorFromZ( bool v, mrpt::utils::TColormap	colorMap = mrpt::utils::cmJET )
			{
				m_colorFromZ = v;
				m_colorMap   = colorMap;
			}

			/** This method sets the matrix of heights for each position (cell) in the mesh grid */
			void setZ( const mrpt::math::CMatrixTemplateNumeric<float> &in_Z );

			/** Returns a reference to the internal Z matrix, allowing changing it efficiently */
			//mrpt::math::CMatrixFloat & getZ();
			inline void getZ(mrpt::math::CMatrixFloat &out) const	{
				//out=CMatrixTemplateNumeric<float>(Z);
				out=Z;
			}

			/** Returns a reference to the internal mask matrix, allowing changing it efficiently */
			//mrpt::math::CMatrixFloat & getMask();
			inline void getMask(mrpt::math::CMatrixFloat &out) const	{
				//out=CMatrixTemplateNumeric<float>(mask);
				out=mask;
			}

			/** This method sets the boolean mask of valid heights for each position (cell) in the mesh grid */
			void setMask( const mrpt::math::CMatrixTemplateNumeric<float> &in_mask );

			/** Sets the (u,v) texture coordinates (in range [0,1]) for each cell */
			void setUV( const mrpt::math::CMatrixTemplateNumeric<float> &in_U, const mrpt::math::CMatrixTemplateNumeric<float> &in_V);

			inline float getXMin() const	{
				return xMin;
			}
			inline float getXMax() const	{
				return xMax;
			}
			inline float getYMin() const	{
				return yMin;
			}
			inline float getYMax() const	{
				return yMax;
			}
			inline void setXMin(const float &nxm)	{
				xMin=nxm;
				trianglesUpToDate=false;
			}
			inline void setXMax(const float &nxm)	{
				xMax=nxm;
				trianglesUpToDate=false;
			}
			inline void setYMin(const float &nym)	{
				yMin=nym;
				trianglesUpToDate=false;
			}
			inline void setYMax(const float &nym)	{
				yMax=nym;
				trianglesUpToDate=false;
			}
			inline void getXBounds(float &min,float &max) const	{
				min=xMin;
				max=xMax;
			}
			inline void getYBounds(float &min,float &max) const	{
				min=yMin;
				max=yMax;
			}
			inline void setXBounds(const float &min,const float &max)	{
				xMin=min;
				xMax=max;
				trianglesUpToDate=false;
			}
			inline void setYBounds(const float &min,const float &max)	{
				yMin=min;
				yMax=max;
				trianglesUpToDate=false;
			}


			/** Class factory  */
			static CMeshPtr Create(bool enableTransparency, float xMin = 0.0f, float xMax = 0.0f, float yMin = 0.0f, float yMax = 0.0f )
			{
				return CMeshPtr( new CMesh( enableTransparency, xMin ,xMax , yMin ,yMax ) );
			}

			/** Render
			  */
			void  render() const;

			/** Assigns a texture image, and disable transparency.
			  */
			void  assignImage(
				const utils::CImage&	img );

			/** Trace ray
			  */
			virtual bool traceRay(const mrpt::poses::CPose3D &o,double &dist) const;

		private:
			/** Constructor
			  */
			CMesh( bool enableTransparency = false, float xMin = 0.0f, float xMax = 0.0f, float yMin = 0.0f, float yMax = 0.0f ) :
				m_textureImage(0,0),
				m_enableTransparency(enableTransparency),
				m_colorFromZ(false),
				m_isWireFrame(false),
				Z(0,0), mask(0,0), U(0,0), V(0,0), C(0,0),
				m_colorMap( mrpt::utils::cmJET ),
				m_modified_Z(true),
				xMin(xMin), xMax(xMax), yMin(yMin), yMax(yMax),
				trianglesUpToDate(false)
			{
				m_color_A = 1.0f;
				m_color_R = 0.0f;
				m_color_G = 0.0f;
				m_color_B = 0.6f;
			}
			/** Private, virtual destructor: only can be deleted from smart pointers */
			virtual ~CMesh() { }

		};

	} // end namespace

} // End of namespace

#endif
