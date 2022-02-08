#pragma once



namespace lil{

    class VertexBuffer{
    public:
        VertexBuffer(float* data, int size);

        void Bind();
        void Unbind();

        unsigned int GetId(){ return m_id; }
    private:
        unsigned int m_id;
    };

    class IndexBuffer{
    public:
        IndexBuffer(unsigned int* data, unsigned int count);

        void Bind();
        void Unbind();

        unsigned int GetCount() { return m_count; }
        unsigned int GetId(){ return m_id; }
    private:
        unsigned int m_id;
        unsigned int m_count;
    };

}
