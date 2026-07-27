#include <map>
#include "protein_translation.h"

namespace protein_translation
{
    std::map<std::string, std::string> protein_map{
        {"AUG", "Methionine"},
        {"UUU", "Phenylalanine"},
        {"UUC", "Phenylalanine"},
        {"UUA", "Leucine"},
        {"UUG", "Leucine"},
        {"UCU", "Serine"},
        {"UCC", "Serine"},
        {"UCA", "Serine"},
        {"UCG", "Serine"},
        {"UAU", "Tyrosine"},
        {"UAC", "Tyrosine"},
        {"UGU", "Cysteine"},
        {"UGC", "Cysteine"},
        {"UGG", "Tryptophan"},
        {"UAA", "\0"},
        {"UAG", "\0"},
        {"UGA", "\0"},
    };

    std::vector<std::string> proteins(const std::string &rna)
    {
        std::vector<std::string> items;
        for (int i = 0; i < rna.size(); i += 3)
        {
            const auto &codon = rna.substr(i, 3);
            auto ite = protein_map.find(codon);
            if (ite != protein_map.end())
            {
                if (ite->second.empty())
                {
                    break;
                }
                items.push_back(ite->second);
            }
        }
        return items;
    }

} // namespace protein_translation
