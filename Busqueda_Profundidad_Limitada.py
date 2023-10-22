class Graph:
    def __init__(self):
        self.vertex_names = {
            1: "Entrada",
            2: "Biblioteca",
            3: "Aulas",
            4: "Laboratorio",
            5: "Gimnasio",
            6: "Parque",
            7: "Baños",
            8: "Cafetería",
            9: "Taller",
            10: "Sala de computo"
        }
        self.graph = {
            1: [2, 5],
            2: [1, 4],
            3: [4,7,8],
            4: [2,3,9],
            5: [1,2,6],
            6: [5,7,10],
            7: [6],
            8: [3],
            9: [4],
            10: [6]
        }

    def DLS(self, start, goal, depth, max_depth):
        if depth > max_depth:
            return None
        if start == goal:
            return [start]

        for neighbor in self.graph[start]:
            path = self.DLS(neighbor, goal, depth + 1, max_depth)
            if path:
                return [start] + path
        return None

    def depth_limited_search(self, start, goal, max_depth):
        for depth in range(max_depth + 1):
            result = self.DLS(start, goal, 0, depth)
            if result:
                return result
        return None

if __name__ == "__main__":
    graph = Graph()
    start_vertex = 1
    goal_vertex = 10
    max_depth = 3

    path = graph.depth_limited_search(start_vertex, goal_vertex, max_depth)

    if path:
        # Imprime el camino encontrado utilizando los nombres de los lugares
        path_names = [graph.vertex_names[vertex] for vertex in path]
        print(f"Camino encontrado de {graph.vertex_names[start_vertex]} a {graph.vertex_names[goal_vertex]}: {path_names}")
    else:
        print(f"No se encontró un camino de {graph.vertex_names[start_vertex]} a {graph.vertex_names[goal_vertex]} dentro del límite de profundidad {max_depth}.")