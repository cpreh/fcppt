//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REFERENCE_DECL_HPP_INCLUDED
#define FCPPT_REFERENCE_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>


namespace fcppt
{

/**
\brief A simple reference wrapper that supports incomplete types

\ingroup fcpptref

C++11's reference is also a function call wrapper, which implies that
the type it holds must be complete. This class's purpose is to allow objects of
incomplete type to be stored as references in containers instead of pointers.
*/
template<
	typename Type
>
class reference
{
public:
	// Do not bind to temporary objects
	reference(
		Type &&
	) = delete;

	using
	type
	=
	Type;

	explicit
	reference(
		type &
	)
	noexcept;

	[[nodiscard]]
	type &
	get() const
	noexcept;
private:
	type *impl_;
};

}

#endif
