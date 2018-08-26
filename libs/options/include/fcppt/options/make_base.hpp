//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONS_MAKE_BASE_HPP_INCLUDED
#define FCPPT_OPTIONS_MAKE_BASE_HPP_INCLUDED

#include <fcppt/make_unique_ptr.hpp>
#include <fcppt/unique_ptr_to_base.hpp>
#include <fcppt/options/base_impl.hpp>
#include <fcppt/options/base_unique_ptr.hpp>
#include <fcppt/options/detail/concrete_impl.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace options
{

/**
\brief Creates an \link fcppt::options::base\endlink.

\ingroup fcpptoptions

Creates a unique pointer to \link fcppt::options::base\endlink, using the
concrete parser \a _parser as its implementation. It is possible that the
result type of \a Parser is a permuted version of \a Result.

\tparam Result The result type of the parser. Must be an \link fcppt::record::object\endlink.
*/
template<
	typename Result,
	typename Parser
>
fcppt::options::base_unique_ptr<
	Result
>
make_base(
	Parser &&_parser
)
{
	return
		fcppt::unique_ptr_to_base<
			fcppt::options::base<
				Result
			>
		>(
			fcppt::make_unique_ptr<
				fcppt::options::detail::concrete<
					Result,
					fcppt::type_traits::remove_cv_ref_t<
						Parser
					>
				>
			>(
				std::forward<
					Parser
				>(
					_parser
				)
			)
		);
}

}
}

#endif
