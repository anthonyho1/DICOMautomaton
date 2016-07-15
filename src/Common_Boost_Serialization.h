//Common_Boost_Serialization.h - A part of DICOMautomaton 2016. Written by hal clark.

#include <string>    

#include <boost/filesystem.hpp>
#include <boost/filesystem/fstream.hpp>

#include "Structs.h"

#include "KineticModel_1Compartment2Input_5Param_Chebyshev_Structs.h"


bool
Common_Boost_Serialize_Drover(const Drover &in, boost::filesystem::path Filename);

bool
Common_Boost_Deserialize_Drover(Drover &out, boost::filesystem::path Filename);



// --- Specific Serialization Routines ---
// Prefer the 'default' serialization routine above.

bool
Common_Boost_Serialize_Drover_to_Gzip_Binary(const Drover &in, boost::filesystem::path Filename);
bool
Common_Boost_Serialize_Drover_to_Gzip_Simple_Text(const Drover &in, boost::filesystem::path Filename);
bool
Common_Boost_Serialize_Drover_to_Gzip_XML(const Drover &in, boost::filesystem::path Filename);

bool
Common_Boost_Serialize_Drover_to_Binary(const Drover &in, boost::filesystem::path Filename);
bool
Common_Boost_Serialize_Drover_to_Simple_Text(const Drover &in, boost::filesystem::path Filename);
bool
Common_Boost_Serialize_Drover_to_XML(const Drover &in, boost::filesystem::path Filename);



// --- Pharmacokinetic model state ---
std::string 
Serialize(const KineticModel_1Compartment2Input_5Param_Chebyshev_Parameters &state);

bool 
Deserialize(const std::string &s, KineticModel_1Compartment2Input_5Param_Chebyshev_Parameters &state);



