//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_BASE_UNIQUE_PTR_FWD_HPP_INCLUDED
#define FCPPT_OPTIONS_BASE_UNIQUE_PTR_FWD_HPP_INCLUDED

#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/options/base_fwd.hpp>


namespace fcppt
{
namespace options
{

/**
\brief A unique pointer for \link fcppt::options::base\endlink.

\ingroup fcpptoptions

\tparam Result The result type of the parser. Must be an \link fcppt::record::object\endlink.
*/
template<
	typename Result
>
using
base_unique_ptr
=
fcppt::unique_ptr<
	fcppt::options::base<
		Result
	>
>;

}
}

#endif
