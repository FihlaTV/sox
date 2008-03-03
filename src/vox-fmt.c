/*
 * File format: raw Dialogic/OKI ADPCM        (c) 2007-8 SoX contributors
 *
 * This library is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or (at
 * your option) any later version.
 *
 * This library is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU Lesser
 * General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, write to the Free Software Foundation,
 * Fifth Floor, 51 Franklin Street, Boston, MA 02111-1301, USA.
 */

#include "sox_i.h"
#include "vox.h"

SOX_FORMAT_HANDLER(vox)
{
  static char const * const names[] = {"vox", NULL};
  static unsigned const write_encodings[] = {SOX_ENCODING_OKI_ADPCM, 4, 0, 0};
  static sox_format_handler_t handler = {
    names, SOX_FILE_MONO,
    sox_vox_start, sox_vox_read, sox_vox_stopread,
    sox_vox_start, sox_vox_write, sox_vox_stopwrite,
    sox_rawseek, write_encodings, NULL
  };
  return &handler;
}
