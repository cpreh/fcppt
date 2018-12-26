//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_CONCRETE_DECL_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_CONCRETE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/reference_fwd.hpp>
#include <fcppt/parse/base_decl.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/detail/concrete_fwd.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

template<
	typename Parser,
	typename Ch,
	typename Skipper
>
class concrete
:
public
	fcppt::parse::base<
		fcppt::parse::result_of<
			Parser
		>,
		Ch,
		Skipper
	>
{
	FCPPT_NONCOPYABLE(
		concrete
	);

	typedef
	fcppt::parse::base<
		fcppt::parse::result_of<
			Parser
		>,
		Ch,
		Skipper
	>
	base_type;
public:
	explicit
	concrete(
		Parser &&
	);

	~concrete()
	override;

	typedef
	typename
	base_type::result_type
	result_type;

	virtual
	fcppt::parse::result<
		result_type
	>
	parse(
		fcppt::reference<
			fcppt::parse::state<
				Ch
			>
		>,
		fcppt::parse::context<
			Skipper
		> const &
	) const
	override;
private:
	Parser const parser_;
};

}
}
}

#endif
