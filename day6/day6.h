//
// Created by antoni on 12/6/22.
//

#ifndef AOC22_DAY6_H
#define AOC22_DAY6_H

#include <string>
#include <unordered_map>

void solve_6(){
    std::string input = "vmsvstvtzvzqvzvssvddsgdddrqrsqqwnnffrwrswwztwzzbssgtstvsshrsrrlvrvzrrsqsvqsqbssqrsrjrsrddqnnfqnnrfnrnffjsjnnqddjjbvvbzzshhsffmtftrrpzznlltclltmltmllzclcwwgzzzqvqhqllcrllqdqpqnqbqggcrcsclssrfsssqhhfzzprrjvrjvvblvbllwccztzggspgggqrqcqjcqjcqcmmffmtmltlwwcpplpqqwhwvhvnnqhqsqlqvvgfgqqddlhhstthzhgzgbzbdzbzlzwlzlpljlgjjqlltrrbmrrvvcttsddfjddmbdbffcrfftvvzppncpcvcdvcvvjjjlttcgtcctrrrgmrgmgwwsgscsffswfwqwnnzmzffpwptpntppbddggsbsddmjmssnzsnstsztttjztjjpddwlwrrlnnzsnnfllqrrqmqhhfddtmmpfmfcfgfllngnvnjjmffwbffsqsmsdstdddjssmlssfpprrgzzzwvvftffczfftccwrrdsrsjrssfnsnttqptqtnqtnqtttjqtjqjzjpzpvzvbzvvjqqvcqcwwgwllbwbjjhsjhhchffgdfgffvddrndrdwdwlwqqfqzzntzzhwzzndnjnsjjmvvlqqqqshhmzzjvvcscqqjjhphnppcprrhnnbsspcscbssnsmmznzsnnszsrzrwrswsgwglwlzznpnwpnnjlnlrnntllhvvdrvvprpptqqlzqzrrgfgfhfvhhcscjjfmmjpmjjvwvtvhvqhqvvqvwvpvsschhlmlrlmljjqnqggbwbmwbwgbwwgllqzllrjlrjjfjzffthhpvvsddvjvvzsvvhghlhqqbnqqlnngsngnccnpccmttmrtmmlmccqbbjssbsqbqddnqqdvdvbvgbvvjfjhjzzfhfzffgccdjcjtjpttcrrffvddwgglrgllbttcqtctqtvtwtggrppzvvbzvzgzsznnsqnsqqnwwzrwwnwbwnnhznhzhchwwvwhwlwlnnmwmfmfrmmnvndnffjgjmgmfmhmtmstthjhbjhjddrqrllnflnnwzwjjthjhwhmmflmlfmfddqgdqgqqwbbdsstssrvvbpbgppfwfvvglvvzgvgmvgvzvdvcctddjqddffrprbrggpgpghhwzhzggqrqsrstrssnttrgrsswsrstsdtdzttzvznzjnzzqssjwswcswsgghqghqgqvggtsswwmbbfrrdcctjtjsttrccqbbtcctcscqsssvmmdhmdmvdmvmsvsrvsrvsszvvrpvrpprvppctclcrrchhtmmbddswddglgrrdcdppcbpbgpbggbssnrnbrbllqwqbwbmmcwmmrjrdjjpsjppblbjbsbsgswsmwmgwgmmqpplzlssvcscnngwgvvffvlvtvtddgqgttjljggfzggmfgfqqtrrdbdbbnjnnbjbwwjjqljlnjjvzvhvlhhhsfhsfscsjcjsjbsjjdbdbpbqqsggcnczcchrhjhphlppnwwhthghhfvfrrbzrbrrcsszfmhrjflswthfrlmjbnhblmsldjpnrdgfbcrftnbcltlctbdthhjzsqvbmppcbhctqbtfhdrtrbzjpnzzvtfjtpqgbtmdcnjgtblhmvrpbrcpqfhpzqvbfqhsrjqwqqnggrlgvwndqrhvpzhswnglngwjdgwcnngrvhtcsblpdshqcwfpzcpmrbzqjfpllbbvlcfjtdqchjsgsqgqzsbfnnqcsvpwfmzdhzmcjfjnczldclvpfpntppqbhfqzqdtfwsvdzhphwpzhqqfflswhtldlrmrqpfdlwwszphrwjqvhpqmrzvblvtvsfpgzdhnlmsgpqnqdtbjqccbtnvqmtdggdsvvfwjzbdpnztmsblpgcrmppblmtfnjvjwmhnwqdmdrvbvsvhgbhjwzjfcqzwtvzlfmpzvpwsdsqphmqlzwfrqdjdbsmfdzllqqfhmcmhchjpbqtjbczhbcllmtqgczdfnjsjhhcsfdhwwbzzjdqtlvgfgfwbqztqftfqhsfvbzjcbmtdzszfsgzpqpvtqnmjhlrtbvfphvhwbnqsnwgpznnwcbbvdqvvzllqpjbqhqwtfzlhqgvmrpjmlvczqgmffsjvgzvnvccgnmdmbcqjqvbnzvdgnbdwbszldjwjdsnplgqnjmlvrlzcvlgtrdndhjmrtczqjqrzzzclrdmdmrgvljstqfhldfzgvhcdtmncqjjnghgwdgnhbjztfgpqnvfhzngqcftpbqsnvgrqpczwptghbssljnftzmbrqmnbvcbsshvmmmczjgnbjwltflndtntmfznmqhzjjtmmtwbflhmqcmlmzrnvfqzmzhhszqmmqwgzcnncjwvdzvczsgbpcscjptfpwhvvvstvqzhtptrmbhttcrdzhljpmclrbnzmvmtbmmdhfgpjjwsldsgdjflhmfrgvmgzvntgmlglfsntpjjwgnpwsjvsnbctwlsqvprlfmsqfdmzdsdvbtsnqzflvtlgrmdhfgfmwrcqjvbwqsblnwlmtqfhdwwlchqljbljwzmmqgqpwfnmjlvhmppzsdjlbvqwmwqwqqsrgzmpzzzzstrtrbwttzjcmlssstpntnrwtgthrfmthbjjmmtcvjnwsdpdndccgncjbjdqbwtlbfcmgvmlbrdzzlzcpctjvldbpvvmsrwrhhtdsrwljtmntcftwvppjvtttgslrdvpglzdnhrgnrzjsczsmtcfclhvncrhsfvbppqrbwsmjbhjmllwwlqvhbljrqpzshqvllzqtjfhdlnghwblzjldcmfgfjgcbfwqldvdppjmsqqqmznwtcgpmlpqmdpzctwjpnstvgjsbzspfbvfcrgzzcdbzfthgbjrnjwpprblnhdcfgpdcmljpqqzchslpvlwqjvsqtnvnfjhpvwjnjzghnbslhmrhwdppgtvzzmhzzzsvldphjlhrfjwrctfcmnzpvvwqrczcsmznflcwzsplrsdvmfghmnbbjdzclnzpbtjllcszzjcqbbczqhbnfpcctbmhfglsdtnzdjrjbjqczqflznfwzsrmpcgvgrjmhtpgllcpdnlrzvqljprnpvcglvmbtbzjwqfrhdngwsrfjsqnhfncnvprrcngjzfdvcnphcchbqhqpbbbzgmbfndlffnrpzvplptnrvjlzfczvsbctmdqrzdnpvrtgnsgdjwqshglspdzbhflfbsfvbrqgfzmhzhshdlcnqhzbnhbhmsgffgsmvglhscqsrsvmszjfgdhsglbqgwwjndscsqvpccwhlvjbtvftdppcscjblwtmpvvchpzwmblmbbrrvwlglfqwtgcffnzljnmtpbcrszvblwfqdslpqlrmnvrhvrzwnprnmntzrpsdcnwfgljldpvjwwzzbpcltnvghqvqnvmmrfqsnbstdctqqgtpzqttnrrdstrtlfzmvvbzzwwchrscqlnpzdmphdwdqdwbszlhwsbfscthndrdvhtgbpsmznlfjpwjchvzbmrflcphhgjfwstjnzlllztgzjmnwcglmhrbztzdnbcbrgrlmpprrbthbhslfrsjsrrrqvwmqghcgdvvsmrqdwwbdnzmnsqfflpbbjvzjdgsfjdjmbhptmrnbqpqhcdwtvbdlrdzsrchqlsrccjfbfrnnrctdsqbnjzzvrlcwphsscppdmsbrqrzddrdvjwfrldccmzwrhrbpcqpnvnbgpsrhvbchmrdtwqrlvpwhqgnppmsdvqdldlrjrzntlsfwmwhjsghddsppchqlltrhlwrccvflwjbvptclqvwdmrmghbngbflfspsjmglzcqjdtdtldmmngljwfqvfwnmfdtrsmlqzszhzccgvbnnwtpbgssrcqlqgrsjqfhhwpvdtsclgsntwvcsfpvwfqnmwhmtldfswqrsvzshfzwlnwhqhwsrqqzlsdhvqfwnhjcvmplcljmlhbtqtrpjfjfdfmlhtfpnszptfnjbldscjgvjhpzflhm";
    int i = 0;
    while (i + 4 <= input.size()){
        std::unordered_map<int, int> buffer;
        buffer[input[i]] =1;
        buffer[input[i+1]] =1;
        buffer[input[i+2]] =1;
        buffer[input[i+3]] =1;
        if (buffer.size() == 4){
            std:: cout << "Found a packet height_at " << i + 4 << std::endl;
            break;
        }
        i++;
    }
    i = 0;
    while (i + 14 <= input.size()){
        std::unordered_map<int, int> buffer;
        for (int k = 0; k < 14; k++){
            buffer[input[i+k]] =1;
        }
        if (buffer.size() == 14){
            std:: cout << "Found a message height_at " << i + 14 << std::endl;
            break;
        }
        i++;
    }
}

#endif //AOC22_DAY6_H
