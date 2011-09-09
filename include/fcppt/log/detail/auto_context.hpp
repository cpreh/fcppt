//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_AUTO_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_AUTO_CONTEXT_HPP_INCLUDED

#include <fcppt/log/optional_context_location.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/noncopyable.hpp>

namespace fcppt
{
namespace log
{
namespace detail
{

class auto_context
{
	FCPPT_NONCOPYABLE(
		auto_context
	);
public:
	auto_context(
		log::optional_context_location const &,
		log::object &
	);

	~auto_context();

	log::optional_context_location const &
	context_location() const;
private:
	log::optional_context_location const context_location_;
};

}
}
}

#endif
