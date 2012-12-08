//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_FORMAT_HPP_INCLUDED
#define FCPPT_ENDIANNESS_FORMAT_HPP_INCLUDED


namespace fcppt
{
namespace endianness
{

/**
\brief An enumeration for the possible endiannesses

\ingroup fcpptendianness
*/
enum class format
{
	/**
	\brief Little endianness

	This means that the least significant bits are in the first byte. It
	is also the most common endianness, because x86 and amd64 architectures
	use it.
	*/
	little,
	/**
	\brief Big endianness

	This means that the most significant bits are in the first byte.
	*/
	big
};

}
}

#endif
