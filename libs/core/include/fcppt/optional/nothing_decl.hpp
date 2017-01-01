//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_NOTHING_DECL_HPP_INCLUDED
#define FCPPT_OPTIONAL_NOTHING_DECL_HPP_INCLUDED

#include <fcppt/optional/nothing_fwd.hpp>
#include <fcppt/optional/object_fwd.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief A polymorphic empty optional

Objects of this class implicitly convert into empty \link fcppt::optional::object\endlink.

\ingroup fcpptoptional
*/
struct nothing
{
	/**
	\brief Returns an empty optional.
	*/
	template<
		typename T
	>
	operator
	fcppt::optional::object<
		T
	> () const;
};

}
}

#endif
