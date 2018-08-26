//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FILESYSTEM_DIRECTORY_RANGE_HPP_INCLUDED
#define FCPPT_FILESYSTEM_DIRECTORY_RANGE_HPP_INCLUDED

#include <fcppt/filesystem/directory_range_fwd.hpp>
#include <fcppt/filesystem/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/path.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace filesystem
{

/**
\brief A range for directory iterators

\ingroup fcpptfilesystem
*/
class directory_range
{
public:
	FCPPT_FILESYSTEM_DETAIL_SYMBOL
	explicit
	directory_range(
		boost::filesystem::path
	);

	FCPPT_FILESYSTEM_DETAIL_SYMBOL
	boost::filesystem::directory_iterator
	begin() const;

	FCPPT_FILESYSTEM_DETAIL_SYMBOL
	boost::filesystem::directory_iterator
	end() const;
private:
	boost::filesystem::directory_iterator begin_;
};

}
}

#endif
