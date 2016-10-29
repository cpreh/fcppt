//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_XVALUE_DECL_HPP_INCLUDED
#define FCPPT_XVALUE_DECL_HPP_INCLUDED

#include <fcppt/xvalue_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief A wrapper that denotes an xvalue

\ingroup fcpptref

In C++, an xvalue is denoted by an rvalue reference that actually binds to an lvalue.
This class makes an xvalue explicit and gives it normal copy semantics.

\tparam Type Must not be const.
*/
template<
	typename Type
>
class xvalue
{
	// Do not bind to temporary objects
	xvalue(
		Type &&
	) = delete;
public:
	static_assert(
		!std::is_const<
			Type
		>::value,
		"Type must not be const"
	);

	typedef
	Type
	type;

	explicit
	xvalue(
		type &
	)
	noexcept;

	type &
	get() const
	noexcept;
private:
	type *impl_;
};

}

#endif
