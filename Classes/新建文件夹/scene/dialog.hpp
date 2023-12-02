#include<stdio.h>

struct Utterance
{
    std::string speaker;
    std::string u;
};

struct Speaker
{
    std::string name;
    std::string file_name;
    Vector pos;
    bool speak=false;
    s2 zorder=-1;
};

struct Dialog
{
    std::map<std::string,Speaker> speakers;
    std::vector<Utterance> utterances;
    std::string speaker;
    std::string utterance;
    s2 u_index;
    s2 s_index;

    void load(std::string file_name)
    {
        speakers.clear();
        utterances.clear();
        speaker="";
        utterance="";
        u_index=s_index=0;

        std::ifstream is(resources_path+file_name);
        char ch;
        s2 j=0;
        s2 flag1=0;
        s2 flag2=0;

        std::string tmp[2];
        

        while(is>>ch)
        {
            if(ch=='-'&&flag1==0)
            {
                j=1;
            }
            else if(ch=='\"')
            {   
                if(flag1==0)
                {
                    tmp[flag2].clear();
                }
                else
                {
                    if(flag2==1)
                    {
                        if(j==0)
                        {
                            char dot;
                            double x,y;
                            is>>dot>>x>>dot>>y;
                            speakers[tmp[0]]={tmp[0],tmp[1],{x,y}};
                        }
                        else
                            utterances.push_back({tmp[0],tmp[1]});
                    }
                    flag2^=1;
                }
                flag1^=1;
            }
            else if(flag1==1)
            {
                tmp[flag2]+=ch;
            }
        }

        speaker=utterances[0].speaker;
    }

    bool next_u()
    {
        u_index++;
        if(u_index<utterances.size())
        {
            s_index=0;
            speaker=utterances[u_index].speaker;
            return true;
        }
        return false;
    }

    void next_s()
    {
        auto &str=utterances[u_index].u;
        if(s_index<str.length())
        {
            auto ch=str[s_index];
            if(ch&0x80)s_index+=2;
            s_index++;
        }
        utterance=str.substr(0,s_index);
    }

    bool deal()
    {
        auto&str=utterances[u_index].u;
        if(s_index<str.length())
        {
            s_index=str.length();
            utterance=str;
            return true;
        }
        else
        {
            s_index=0;
            return next_u();
        }
    }
};
