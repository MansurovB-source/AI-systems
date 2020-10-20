#include <iostream>

#include <string>

#include <vector>

//#include <unordered_map>
#include <map>

#include <queue>

#include <algorithm>

#include <climits>

using namespace std;
int n = 27;

struct City {
  string name;
  int distinct;
};

// unordered_map < string, vector < City >> cities(27);
// unordered_map < string, bool > visited(27, 0);
// unordered_map < string, string > parent;
// unordered_map < string, int > dest;
// unordered_map < string, int > ufa;

map < string, vector < City >> cities;
map < string, bool > visited;
map < string, string > parent;
map < string, int > dest;
map < string, int > ufa;

void v_clear() {
    for(auto it = visited.begin(); it != visited.end(); it++) {
        //cout << it -> first << "\n";
        it -> second = false;
    }
}

void p_clear() {
    for(auto it = parent.begin(); it != parent.end(); it++) {
        //cout << it -> first << "\n";
        it -> second = "null";
    }
}

void uca_modified(string from) {
  dest[from] = 0;
  for (auto it = cities.begin(); it != cities.end(); ++it) {
    string v = "null";
    for (auto itr = cities.begin(); itr != cities.end(); ++itr) {
      if (!visited[itr -> first] && (v == "null" || dest[itr -> first] + ufa[itr -> first] < dest[v] + ufa[v])) {
        v = itr -> first;
      }
    }
    if (dest[v] == INT_MAX) {
      break;
    }
    visited[v] = true;
    for (auto iter = cities[v].begin(); iter != cities[v].end(); ++iter) {
      string to = iter -> name;
      int len = iter -> distinct;
      if (dest[v] + len < dest[to]) {
        dest[to] = dest[v] + len;
        parent[to] = v;
      }
    }
  }
}

void uca(string from) {
  dest[from] = 0;
  for (auto it = cities.begin(); it != cities.end(); ++it) {
    string v = "null";
    for (auto itr = cities.begin(); itr != cities.end(); ++itr) {
      if (!visited[itr -> first] && (v == "null" || dest[itr -> first] < dest[v])) {
        v = itr -> first;
      }
    }
    if (dest[v] == INT_MAX) {
      break;
    }
    visited[v] = true;
    for (auto iter = cities[v].begin(); iter != cities[v].end(); ++iter) {
      string to = iter -> name;
      int len = iter -> distinct;
      if (dest[v] + len < dest[to]) {
        dest[to] = dest[v] + len;
        parent[to] = v;
      }
    }
  }
}

bool dls(string from, string to, int limit) {
  visited[from] = true;
  if (from == to) {
    return true;
  }
  if (limit == 0) {
    return false;
  }
  for (auto it = cities[from].begin(); it != cities[from].end(); ++it) {
    string t = it -> name;
    if (!visited[t]) {
      parent[t] = from;
      if (dls(t, to, limit - 1)) {
        return true;
      }
    }
  }
  return false;
}

void iddfs(string from, string to) {
  for (int i = 1;; i++) {
    v_clear();
    bool result = dls(from, to, i);
    if (result == true) {
      break;
    }
  }
}

void dfs(string from) {
  visited[from] = true;
  for (auto it = cities[from].begin(); it != cities[from].end(); ++it) {
    string t = it -> name;
    if (!visited[t]) {
      parent[t] = from;
      dfs(t);
    }
  }
}

void bfs(string from) {
  queue < string > q;
  q.push(from);
  parent[from] = "null";
  visited[from] = true;
  while (!q.empty()) {
    string v = q.front();
    q.pop();
    for (auto it = cities[v].begin(); it != cities[v].end(); ++it) {
      string t = it -> name;
      if (!visited[t]) {
        visited[t] = true;
        q.push(t);
        parent[t] = v;
      }
    }
  }
}

void shortPath(string to) {
  vector < string > path;
  if (!visited[to]) {
    cout << "No path\n";
  } else {
    string s = to;
    while (s != "null") {
      path.push_back(s);
      s = parent[s];
    }
    reverse(path.begin(), path.end());
    for (int i = 0; i < path.size() - 1; i++) {
      cout << path[i] << " --> ";
    }
    cout << path[path.size() - 1];
  }
}

int main() {
  int max = INT_MAX;
  ufa["Брест"] = 2133;
  ufa["Вильнюс"] = 1954;
  ufa["Витебск"] = 1627;
  ufa["Волгоград"] = 1031;
  ufa["Воронеж"] = 1163;
  ufa["Даугавпилс"] = 1853;
  ufa["Донецк"] = 1458;
  ufa["Житомир"] = 1900;
  ufa["Казань"] = 443;
  ufa["Калининград"] = 2252;
  ufa["Каунас"] = 2036;
  ufa["Киев"] = 1771;
  ufa["Кишинев"] = 2070;
  ufa["Минск"] = 1831;
  ufa["Москва"] = 1165;
  ufa["Мурманск"] = 1962;
  ufa["Ниж.Новгород"] = 772;
  ufa["Одесса"] = 1987;
  ufa["Орел"] = 1314;
  ufa["Рига"] = 1986;
  ufa["С.Петербург"] = 1632;
  ufa["Самара"] = 418;
  ufa["Симферополь"] = 1895;
  ufa["Таллин"] = 1937;
  ufa["Харьков"] = 1431;
  ufa["Ярослав"] = 1042;

  dest["Брест"] = max;
  dest["Вильнюс"] = max;
  dest["Витебск"] = max;
  dest["Волгоград"] = max;
  dest["Воронеж"] = max;
  dest["Даугавпилс"] = max;
  dest["Донецк"] = max;
  dest["Житомир"] = max;
  dest["Казань"] = max;
  dest["Калининград"] = max;
  dest["Каунас"] = max;
  dest["Киев"] = max;
  dest["Кишинев"] = max;
  dest["Минск"] = max;
  dest["Москва"] = max;
  dest["Мурманск"] = max;
  dest["Ниж.Новгород"] = max;
  dest["Одесса"] = max;
  dest["Орел"] = max;
  dest["Рига"] = max;
  dest["С.Петербург"] = max;
  dest["Самара"] = max;
  dest["Симферополь"] = max;
  dest["Таллин"] = max;
  dest["Уфа"] = max;
  dest["Харьков"] = max;
  dest["Ярослав"] = max;

  cities["Брест"] = {
    {
      "Вильнюс",
      531
    },
    {
      "Витебск",
      638
    },
    {
      "Калининград",
      699
    }
  };
  cities["Вильнюс"] = {
    {
      "Брест",
      531
    },
    {
      "Витебск",
      360
    },
    {
      "Даугавпилс",
      211
    },
    {
      "Калининград",
      333
    },
    {
      "Каунас",
      102
    },
    {
      "Киев",
      634
    }
  };
  cities["Витебск"] = {
    {
      "Брест",
      638
    },
    {
      "Вильнюс",
      360
    },
    {
      "Волгоград",
      1455
    },
    {
      "Воронеж",
      869
    },
    {
      "Ниж.Новгород",
      911
    },
    {
      "Орел",
      522
    },
    {
      "С.Петербург",
      602
    }
  };
  cities["Волгоград"] = {
    {
      "Витебск",
      1455
    },
    {
      "Воронеж",
      581
    },
    {
      "Житомир",
      1493
    }
  };
  cities["Воронеж"] = {
    {
      "Витебск",
      869
    },
    {
      "Волгоград",
      581
    },
    {
      "Ярославль",
      739
    }
  };
  cities["Даугавпилс"] = {
    {
      "Вильнюс",
      211
    }
  };
  cities["Донецк"] = {
    {
      "Житомир",
      863
    },
    {
      "Кишинев",
      812
    },
    {
      "Москва",
      1084
    },
    {
      "Орел",
      709
    }
  };
  cities["Житомир"] = {
    {
      "Волгоград",
      1493
    },
    {
      "Донецк",
      863
    },
    {
      "Киев",
      131
    }
  };
  cities["Казань"] = {
    {
      "Москва",
      815
    },
    {
      "Уфа",
      525
    }
  };
  cities["Калининград"] = {
    {
      "Брест",
      699
    },
    {
      "Вильнюс",
      333
    },
    {
      "С.Петербург",
      739
    }
  };
  cities["Каунас"] = {
    {
      "Вильнюс",
      102
    },
    {
      "Рига",
      267
    }
  };
  cities["Киев"] = {
    {
      "Вильнюс",
      634
    },
    {
      "Житомир",
      131
    },
    {
      "Кишенев",
      467
    },
    {
      "Одесса",
      487
    },
    {
      "Харьков",
      471
    }
  };
  cities["Кишенев"] = {
    {
      "Донецк",
      812
    },
    {
      "Киев",
      467
    }
  };
  cities["Минск"] = {
    {
      "Москва",
      690
    },
    {
      "Мурманск",
      2238
    },
    {
      "Ярославль",
      940
    }
  };
  cities["Москва"] = {
    {
      "Донецк",
      1084
    },
    {
      "Казань",
      815
    },
    {
      "Минск",
      690
    },
    {
      "Ниж.Новгород",
      411
    },
    {
      "Орел",
      368
    },
    {
      "С.Петербург",
      664
    }
  };
  cities["Мурманск"] = {
    {
      "Минск",
      2238
    },
    {
      "С.Петербург",
      1412
    }
  };
  cities["Ниж.Новгород"] = {
    {
      "Витебск",
      911
    },
    {
      "Москва",
      411
    }
  };
  cities["Одесса"] = {
    {
      "Киев",
      487
    }
  };
  cities["Орел"] = {
    {
      "Витебск",
      522
    },
    {
      "Донецк",
      709
    },
    {
      "Москва",
      368
    }
  };
  cities["Рига"] = {
    {
      "Каунас",
      267
    },
    {
      "С.Петербург",
      641
    },
    {
      "Таллин",
      308
    }
  };
  cities["С.Петербург"] = {
    {
      "Витебск",
      602
    },
    {
      "Калининград",
      739
    },
    {
      "Москва",
      664
    },
    {
      "Мурманск",
      1412
    },
    {
      "Рига",
      641
    }
  };
  cities["Самара"] = {
    {
      "Уфа",
      461
    }
  };
  cities["Симферополь"] = {
    {
      "Харьков",
      639
    }
  };
  cities["Таллин"] = {
    {
      "Рига",
      308
    }
  };
  cities["Уфа"] = {
    {
      "Казань",
      525
    },
    {
      "Самара",
      461
    }
  };
  cities["Харьков"] = {
    {
      "Киев",
      471
    },
    {
      "Симферополь",
      639
    }
  };
  cities["Ярославль"] = {
    {
      "Воронеж",
      739
    },
    {
      "Минск",
      940
    }
  };

  parent["Рига"] = "null";

  cout << "--------------\n";
  cout << "Поиск в ширину \n";
  bfs("Рига");
  shortPath("Уфа");
  v_clear();
  p_clear();

  cout <<"\n";
  cout << "--------------\n";
  cout << "Поиск в глубину \n";
  dfs("Рига");
  shortPath("Уфа");
  v_clear();
  p_clear();

  cout <<"\n";
  cout << "--------------\n";
  cout << "Поиск с ограничением глубины \n";
  dls("Рига", "Уфа", 13);
  shortPath("Уфа");
  v_clear();
  p_clear();

  cout <<"\n";
  cout << "--------------\n";
  cout << "Поиск в глубины с итеративным углублением \n";
  iddfs("Рига", "Уфа");
  shortPath("Уфа");
  v_clear();
  p_clear();
  
  cout <<"\n";
  cout << "--------------\n";
  cout << "Поиск по критерию стоимости \n";
  uca("Рига");
  shortPath("Уфа");
  cout << " : " << dest["Уфа"] << "\n";
  v_clear();
  p_clear();

  cout <<"\n";
  cout << "--------------\n";
  cout << "Поиск по критерию стоимости с использованием информации до цели по прямой \n";
  uca_modified("Рига");
  shortPath("Уфа");
  //cout << " : " << dest["Уфа"] << "\n";
  v_clear();
  p_clear();

  return 0;
}
