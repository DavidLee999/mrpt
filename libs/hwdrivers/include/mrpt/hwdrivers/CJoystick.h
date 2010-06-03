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
#ifndef  CJOYSTICK_H
#define  CJOYSTICK_H

#include <mrpt/config.h>
#include <mrpt/utils/utils_defs.h>
#include <mrpt/hwdrivers/link_pragmas.h>

/*---------------------------------------------------------------
	Class
  ---------------------------------------------------------------*/
namespace mrpt
{
	namespace hwdrivers
	{
		/** Access to joysticks and gamepads (read buttons and position), and request number of joysticks in the system.
		  *  Since MRPT 0.6.0 this class works in Windows and Linux.
		  */
		class HWDRIVERS_IMPEXP CJoystick
		{
		private:
			/** The axis limits:
			 */
			int 	m_x_min,m_x_max,m_y_min,m_y_max,m_z_min,m_z_max;


	#if defined(MRPT_OS_LINUX)
			int			m_joy_fd;		//!< File FD for the joystick, or -1 if not open (Linux only)
			int			m_joy_index;	//!< The index of the joystick open in m_joy_fd (Linux only)
			/** Using an event system we only have deltas, need to keep the whole joystick state (Linux only) */
			vector_bool	m_joystate_btns;
			/** Using an event system we only have deltas, need to keep the whole joystick state (Linux only) */
			vector_int	m_joystate_axes;
	#endif

		public:
			/** Constructor
			 */
			CJoystick();

			/** Destructor
			 */
			virtual ~CJoystick();

			/** Returns the number of Joysticks in the computer.
			 */
			static int  getJoysticksCount();

			/** Gets joystick information.
			 *
			 *   This method will try first to open the joystick, so you can safely call it while the joystick is plugged and removed arbitrarly.
			 *
			 * \param nJoy The index of the joystick to query: The first one is 0, the second 1, etc... See CJoystick::getJoysticksCount to discover the number of joysticks in the system.
			 * \param x The x axis position, range [-1,1]
			 * \param y The y axis position, range [-1,1]
			 * \param z The z axis position, range [-1,1]
			 * \param buttons Each element will hold true if buttons are pressed. The size of the vector will be set automatically to the number of buttons.
			 * \param raw_x_pos If it is desired the raw integer measurement from JoyStick, set this pointer to a desired placeholder.
			 * \param raw_y_pos If it is desired the raw integer measurement from JoyStick, set this pointer to a desired placeholder.
			 * \param raw_z_pos If it is desired the raw integer measurement from JoyStick, set this pointer to a desired placeholder.
			 *
			 * \return Returns true if successfull, false on error, for example, if joystick is not present.
			 *
			 * \sa setLimits
			 */
			bool  getJoystickPosition(
				int 	nJoy,
				float 	&x,
				float 	&y,
				float 	&z,
				std::vector<bool>	&buttons,
				int *raw_x_pos=NULL,
				int	*raw_y_pos=NULL,
				int *raw_z_pos=NULL );

			/** Set the axis limit values, for computing a [-1,1] position index easily (Only required to calibrate analog joystick).
			 *   It seems that these values must been calibrated for each joystick model.
			 *
			 * \sa getJoystickPosition
			 */
	#ifdef MRPT_OS_WINDOWS
			void  setLimits( int x_min = 0,int x_max = 0xFFFF, int y_min=0,int y_max = 0xFFFF,int z_min=0,int z_max = 0xFFFF );
	#else
			void  setLimits( int x_min = -32767,int x_max = 32767, int y_min=-32767,int y_max = 32767,int z_min=-32767,int z_max = 32767);
	#endif
		}; // End of class def.

	} // End of namespace
} // End of namespace

#endif
