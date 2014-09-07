class Solution:
    # @param start, a string
    # @param end, a string
    # @param dict, a set of string
    # @return a list of lists of string
    def findLadders(self, start, end, dict):
        if not hasattr(self, 'alphabets'):
            self.alphabets = [chr(x) for x in xrange(ord('a'), ord('z') + 1)]
        if not hasattr(self, 'cache'):
            self.cache = {}
            
        try:
            return self.cache[start][end]
        except KeyError:
            pass
        
        # Initialize
        if start not in self.cache:
            self.cache[start] = {}
            self.cache[start][end] = []
        elif end not in self.cache[start]:
            self.cache[start][end] = []
        
        if end not in self.cache:
            self.cache[end] = {}
            self.cache[end][start] = []
        elif start not in self.cache[end]:
            self.cache[end][start] = []
        # Initialization done
        
        for idx in range(len(start)):
            for alpha in self.alphabets:
                if alpha == start[idx]: continue
                new_elem = start[:idx] + alpha + start[idx + 1:]
                if new_elem in dict:
                    further_path_list = self.findLadders(new_elem, end, dict)
                    for further_path in further_path_list:
                        self.cache[start][end].append([start] + further_path)
                        
        for path in self.cache[start][end]:
            self.cache[end][start].append(list(reversed(path)))
            
        return self.cache[start][end]
        
if __name__ == '__main__':
    a = Solution()
    print a.findLadders("nape", "mild", ["dose","ends","dine","jars","prow","soap","guns","hops","cray","hove","ella","hour","lens","jive","wiry","earl","mara","part","flue","putt","rory","bull","york","ruts","lily","vamp","bask","peer","boat","dens","lyre","jets","wide","rile","boos","down","path","onyx","mows","toke","soto","dork","nape","mans","loin","jots","male","sits","minn","sale","pets","hugo","woke","suds","rugs","vole","warp","mite","pews","lips","pals","nigh","sulk","vice","clod","iowa","gibe","shad","carl","huns","coot","sera","mils","rose","orly","ford","void","time","eloy","risk","veep","reps","dolt","hens","tray","melt","rung","rich","saga","lust","yews","rode","many","cods","rape","last","tile","nosy","take","nope","toni","bank","jock","jody","diss","nips","bake","lima","wore","kins","cult","hart","wuss","tale","sing","lake","bogy","wigs","kari","magi","bass","pent","tost","fops","bags","duns","will","tart","drug","gale","mold","disk","spay","hows","naps","puss","gina","kara","zorn","boll","cams","boas","rave","sets","lego","hays","judy","chap","live","bahs","ohio","nibs","cuts","pups","data","kate","rump","hews","mary","stow","fang","bolt","rues","mesh","mice","rise","rant","dune","jell","laws","jove","bode","sung","nils","vila","mode","hued","cell","fies","swat","wags","nate","wist","honk","goth","told","oise","wail","tels","sore","hunk","mate","luke","tore","bond","bast","vows","ripe","fond","benz","firs","zeds","wary","baas","wins","pair","tags","cost","woes","buns","lend","bops","code","eddy","siva","oops","toed","bale","hutu","jolt","rife","darn","tape","bold","cope","cake","wisp","vats","wave","hems","bill","cord","pert","type","kroc","ucla","albs","yoko","silt","pock","drub","puny","fads","mull","pray","mole","talc","east","slay","jamb","mill","dung","jack","lynx","nome","leos","lade","sana","tike","cali","toge","pled","mile","mass","leon","sloe","lube","kans","cory","burs","race","toss","mild","tops","maze","city","sadr","bays","poet","volt","laze","gold","zuni","shea","gags","fist","ping","pope","cora","yaks","cosy","foci","plan","colo","hume","yowl","craw","pied","toga","lobs","love","lode","duds","bled","juts","gabs","fink","rock","pant","wipe","pele","suez","nina","ring","okra","warm","lyle","gape","bead","lead","jane","oink","ware","zibo","inns","mope","hang","made","fobs","gamy","fort","peak","gill","dino","dina","tier"])

