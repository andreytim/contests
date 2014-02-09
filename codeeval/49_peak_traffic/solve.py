#!/usr/bin/python

import sys

class Graph:

    edges = dict()

    def add_edge(self, v1, v2):
        if not v1 in self.edges: self.edges[v1] = set()
        if not v2 in self.edges: self.edges[v2] = set()
        self.edges[v1].add(v2)
        self.edges[v2].add(v1)

    def vertices(self):
        return set(self.edges.keys())

    def degree(self, v):
        return len(self.edges[v])

    def neighbors(self, v):
        return self.edges[v]

    def to_string(self):
        res = []
        for v in self.edges:
            res.append('%s -> %s' % (v, ', '.join(sorted(self.edges[v]))))
        return '\n'.join(res)

def mce_BK(R, P, X, g, cliques):
    if not P and not X:
        cliques.append(R)
    for v in degeneracy_ordering(P, g):
        mce_BK(R | set([v]), P & g.neighbors(v), X & g.neighbors(v), g, cliques)
        P.remove(v)
        X.add(v)

def degeneracy_ordering(P, g):
    return [ v[1] for v in sorted([ (g.degree(v), v) for v in P ]) ]

def main():
    f = open(sys.argv[1], 'r')
    actions = dict()
    g = Graph()
    for l in f.readlines():
        date, u1, u2 = l.strip().split('\t')
        if not u1 in actions: actions[u1] = set()
        if not u2 in actions: actions[u2] = set()
        actions[u1].add(u2)
        if u2 in actions[u1] and u1 in actions[u2]:
            g.add_edge(u1, u2)
    cliques = []
    mce_BK(set(), g.vertices(), set(), g, cliques)
    print '\n'.join(sorted([ ', '.join(sorted(cl)) for cl in cliques if len(cl) >= 3]))
    f.close()

if __name__ == '__main__':
    main()
