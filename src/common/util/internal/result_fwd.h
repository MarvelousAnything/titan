/**
 * This file is part of the Titan Avionics Library
 * Copyright (c) 2024 Aaron McBride.
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, version 3.
 * 
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 * 
 * @file common/util/internal/result_fwd.h 
 * @authors Aaron McBride 
 * @brief Contains forward declaration for the result class.
 * @note - This file is internal to the 'util' component.
 */

#pragma once

namespace ti::util {

  template<typename V, typename E>
  class Result;

  template<typename T>
  struct Valid;

  template<typename T>
  struct Error;

  template<typename T> Valid(T) -> Valid<T>;
  template<typename T> Error(T) -> Error<T>;

} // namespace ti::util